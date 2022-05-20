#include "GPIO.h"
#include "stm32f401cc_interface.h"

/**
 * @file main.c
 * @author mohamed abdelaziz (mohamed.ahmed997@eng-st.cu.edu.eg)
 * @brief Task 03 - Add a GPIO_ReadPin function to the GPIO driver. Use the complete driver to perform the same actions of HW Task 2.
 * @version 0.2
 * @date 8-12-2021
 * 
 * Supervisors: Eng.Alaa Malik - Eng. Abdullah Darwish
 * 
 */



int main(){
	char i ;
	char color = RED;
	// Port B pin3 as input pull up
	GPIO_Init('B', 3 , INPUT, PULL_UP);
	// Port B pins [5,6,7] as output push pull 
	for(i = 5 ; i<8 ; i++){
		GPIO_Init('B', i , OUTPUT, PUSH_PULL);
	}

	while(1){
		// Do nothing till the button is pressed
	   while (GPIO_ReadPin('B',3) == 1)  
	   {}
	   // if pressed call rgb_led_display()
	   color = rgb_led_display(color);   
	   // check if the button is still pressed if it is don't do anything  and if not call rgb_turn_off
	   while(GPIO_ReadPin('B',3) == 0){} 
	   rgb_turn_off();
	}

		  return 0;
}


char rgb_led_display(char color){
	switch(color){
	case(RED):
		GPIO_WritePin('B',5,1);
		GPIO_WritePin('B',6,0);
		GPIO_WritePin('B',7,0);
		return GREEN ;
	case(GREEN):
		GPIO_WritePin('B',5,0);
		GPIO_WritePin('B',6,1);
		GPIO_WritePin('B',7,0);
		return BLUE ;
	case(BLUE):
		GPIO_WritePin('B',5,0);
		GPIO_WritePin('B',6,0);
		GPIO_WritePin('B',7,1);
		return YELLOW ;
	case(YELLOW):
		GPIO_WritePin('B',5,1);
		GPIO_WritePin('B',6,1);
		GPIO_WritePin('B',7,0);
		return CYAN  ;
	case(CYAN):
	    GPIO_WritePin('B',5,0);
		GPIO_WritePin('B',6,1);
		GPIO_WritePin('B',7,1);
		return PURPLE ;
	case(PURPLE):
		GPIO_WritePin('B',5,1);
		GPIO_WritePin('B',6,0);
		GPIO_WritePin('B',7,1);
		return WHITE ;
	case(WHITE):
		GPIO_WritePin('B',5,1);
		GPIO_WritePin('B',6,1);
		GPIO_WritePin('B',7,1);
		return RED ;
	} // End of Switch
}


void rgb_turn_off(void){
	GPIO_WritePin('B',5,0);
	GPIO_WritePin('B',6,0);
	GPIO_WritePin('B',7,0);
}

