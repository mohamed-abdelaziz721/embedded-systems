#include "GPIO.h"
#include "Keypad.h"


const unsigned char key_pad_map_array[4][3]= {{0x01,0x02,0x03},{0x04,0x05,0x06},{0x07,0x08,0x09},{'*',0x00,'#'}};
static unsigned char key ;


void KEYPAD_Init(void){
	 GPIO_EnableClock(1);
	 unsigned char k ;
	 for(k = 8 ; k<11 ; k++)
	 {
	 GPIO_Init(1, k, OUTPUT,PUSH_PULL);//make port B pins 8,9,10 output
	 }
	 unsigned char i ;
	 for (i = 0 ; i<4 ; i++){
	 GPIO_Init(1, i, INPUT,PULL_UP);//make port B pins 0,1,2,3 input
	 }
}

unsigned char KEYPAD_GetKey(void){

    return key;
}



void KEYPAD_Manage(void)
{

	  unsigned char row;
	  unsigned char column;


	  for(column =8 ; column <11 ; column++)
	  		{
		              GPIO_WritePin(1,column,0);//put 0 in port B column 0
		  	  	      for(row =0 ; row<4 ; row++)
	  				  {
	  					if(GPIO_ReadPin(1,row) == 0) // 1, row means that read from port B and the selected row
	  					  {

	  						for (unsigned int i = 0; i < 30000; i++)
	  						{}
	  						if(GPIO_ReadPin(1,row) == 0)
	  						{
	  							key = key_pad_map_array[row][column-8];
	  							KEYPAD_Callouts_KeyPressNotification();
	  						}

	  						//segment_turnoff();  if you wanna turn off after releasing and return to blank
	  						}
	  			      }
       		  GPIO_WritePin(1,column,1);//write one on port b on the selected pin


	  		}

}




