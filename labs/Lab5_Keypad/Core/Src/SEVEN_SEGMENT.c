#include "SEVEN_SEGMENT.h"
#include "GPIO.h"

void SEVEN_SEGMENT_Init(void){
	unsigned char i ;
	  GPIO_EnableClock('A');
	  for (i = 0; i < 7; i++) {
	     GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	   }
}

void SEVEN_SEGMENT_Off(void){
	 unsigned char i ;
		for (i = 0; i < 7; i++){
		    GPIO_WritePin('A', i, 0);
	    }
}
