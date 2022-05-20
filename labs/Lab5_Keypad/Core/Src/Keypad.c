#include "GPIO.h"
#include "Keypad.h"

static unsigned char key ;
const unsigned char key_pad_map_array[4][3]= {{0x01,0x02,0x03},
											  {0x04,0x05,0x06},
											  {0x07,0x08,0x09},
											  {'*', 0x00, '#'}};

void KEYPAD_Init(void){
	 GPIO_EnableClock('B');
	 /* Set Port B pins 8, 9, 10 as output Push_Pull  */  
	 for(unsigned char k = 8 ; k < 11 ; k++)
	 {
	 GPIO_Init('B', k, OUTPUT,PUSH_PULL);
	 }
	 /* Set Port B pins 0, 1, 2, 3 as input Pull_up  */
	 for (unsigned char i = 0 ; i < 4 ; i++){
	 GPIO_Init('B', i, INPUT,PULL_UP);
	 }
}

unsigned char KEYPAD_GetKey(void){return key;}

void KEYPAD_Manage(void){
  unsigned char row;
  unsigned char column;
  for(column = 8 ; column <11 ; column++){
	  GPIO_WritePin('B',column,0);
	  for(row =0 ; row < 4 ; row++){
  		if(GPIO_ReadPin('B',row) == 0){
  			key = key_pad_map_array[row][column-8];
  			KEYPAD_Callouts_KeyPressNotification();
  			while(GPIO_ReadPin('B',row)== 0 ){}
  		}
  	}
	  GPIO_WritePin('B',column,1);
  }
}

