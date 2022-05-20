/*
 * GPIO.C
 *
 *  Created on: Nov 24, 2021
 *      Author: ADVINTIC
 */

#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
void GPIO_init( char Port, unsigned int Pin_no, unsigned int Pin_dir, unsigned int Default_State){
/**
 * @brief this is the general purpose input output driver.
 *  this handle the pin assignment to a port and set its direction along with its state. 
 */


switch (Port){	
	case('A'):
		/* Enable clock of port */
		RCC_AHB1ENR |= (0x01 <<0);
		//configure moder register for pin direction
		switch(Pin_dir){
			case (INPUT):
					GPIOA_MODER &= ~(0x03 << 2*Pin_no);
			break;
			case (OUTPUT):
					GPIOA_MODER |= (0x01 << 2*Pin_no);
			break;
			case (ALTERNATE_FUN):
					GPIOA_MODER |= (0x02 << 2*Pin_no);
			break;
			case (ANALOG):
					GPIOA_MODER |= (0x03 << 2*Pin_no);
			break;
		}
		switch(Default_State){
			/*configure default state*/
			case(PUSH_PULL):
					GPIOA_OTYPER &= ~(0x01<<Pin_no);
			break;
			case(OPEN_DRAIN):
					GPIOA_OTYPER |= (0x01<<Pin_no);
			break;
		}
	break;
	case('B'):
		/* Configure pin direction using moder register*/
		RCC_AHB1ENR |= (0x01 <<1);
		switch(Pin_dir){
			case (INPUT):
					GPIOB_MODER &= ~(0x03 << 2*Pin_no);
			break;
			case (OUTPUT):
					GPIOB_MODER |= (0x01 << 2*Pin_no);
			break;
			case (ALTERNATE_FUN):
					GPIOB_MODER |= (0x02 << 2*Pin_no);
			break;
			case (ANALOG):
					GPIOB_MODER |= (0x03 << 2*Pin_no);
			break;
		}
		switch(Default_State){
			case(PUSH_PULL):
					GPIOB_OTYPER &= ~(0x01<<Pin_no);
			break;
			case(OPEN_DRAIN):
					GPIOB_OTYPER |= (0x01<<Pin_no);
			break;
		}
	break;
}

}

unsigned char GPIO_writePin(char Port, unsigned int Pin_no, unsigned int Data){
	unsigned char result;
	switch(Port){
		case('A'):
			if((GPIOA_MODER & (0x03 << 2*Pin_no)) >> (2*Pin_no) == 1){
				 if(Data){GPIOA_ODR |= (1<<Pin_no);}
				 else{GPIOA_ODR &= ~(1<<Pin_no);}
				result = OK;
			}
			else{result = NOK;}
		break;
		case('B'):
				if((GPIOB_MODER & (0x01 << 2*Pin_no))>> (2*Pin_no)){
					 if(Data){GPIOB_ODR |= (1<<Pin_no);}
					 else{GPIOB_ODR &= ~(1<<Pin_no);}
					result = OK;
				}
				else{result = NOK;}	
		break;
	}
	return result;
}
