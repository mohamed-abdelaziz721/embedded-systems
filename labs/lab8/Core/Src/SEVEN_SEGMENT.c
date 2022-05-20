#include "SEVEN_SEGMENT.h"
#include "GPIO.h"

void SEVEN_SEGMENT_Init(void){
	unsigned char i ;
	  GPIO_EnableClock(1);// zero means port A
	  for (i = 0; i < 7; i++) {
	     GPIO_Init( 0, i, OUTPUT, PUSH_PULL);// zero in the functions means PORT A
	   }
}
void SEVEN_SEGMENT_Off(void){
	 unsigned char i ;
		   for (i = 0; i < 7; i++) {
		 	            GPIO_WritePin( 0, i, 0);
		 	          }
}
