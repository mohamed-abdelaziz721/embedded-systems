
#include "GPIO.h"
#include "KEYPAD.h"
#include "SEVEN_SEGMENT.h"


unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void) {
  SEVEN_SEGMENT_Init();
  KEYPAD_Init();
  SEVEN_SEGMENT_Off();




  while (1) {

	 KEYPAD_Manage();

 }
  return 0;
}

void  KEYPAD_Callouts_KeyPressNotification(void){
	unsigned char key = KEYPAD_GetKey() ;
	unsigned char i ;
	if(key == '#'){SEVEN_SEGMENT_Off();}
	if(key < 10){
	for (i = 0; i < 7; i++) {
	 	            GPIO_WritePin( 0 , i, (sevenSegHex[key] & (1 << i)) >> i);
	 	          }
	}
	else{
		SEVEN_SEGMENT_Off();
	}
}




