
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
void GPIO_Init( char Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State){
	//Enable port clock 
	switch (Port){
		case('A'):
			RCC_AHB1ENR |= (0x01 <<0);
			//Configure Pin Direction
			switch(PIN_Dir){
				case (INPUT):
					GPIOA_MODER &= ~(0x03 << 2*PIN_NO);
				break;

				case (OUTPUT):
					GPIOA_MODER |= (0x01 << 2*PIN_NO);
				break;

				case (ALTERNATE_FUN):
					GPIOA_MODER |= (0x02 << 2*PIN_NO);
				break;

				case (ANALOG):
					GPIOA_MODER |= (0x03 << 2*PIN_NO);
				break;

			}// End of Switch
		
			switch(Default_State)
			{
				case(PUSH_PULL):
					GPIOA_OTYPER &= ~(0x01<<PIN_NO);
				break;

				case(OPEN_DRAIN):
					GPIOA_OTYPER |= (0x01<<PIN_NO);
				break;

				case(PULL_UP):
					GPIOA_PUPDR &= ~(0x03<<2*PIN_NO);
					GPIOA_PUPDR   |=  (0x01<<2*PIN_NO);
				break;

				case(PULL_DOWN):
					GPIOA_PUPDR &= ~(0x03<<2*PIN_NO);
					GPIOA_PUPDR   &=  ~(0x02<<2*PIN_NO);
				break;
			}//End of Switch
		break;

		case('B'):
				RCC_AHB1ENR |= (0x01 <<1);
			    //Configure Pin Direction
				switch(PIN_Dir)
				{
					case (INPUT):
						GPIOB_MODER &= ~(0x03 << 2*PIN_NO);
					break;

					case (OUTPUT):
						GPIOB_MODER |= (0x01 << 2*PIN_NO);
					break;

					case (ALTERNATE_FUN):
						GPIOB_MODER |= (0x02 << 2*PIN_NO);
					break;

					case (ANALOG):
						GPIOB_MODER |= (0x03 << 2*PIN_NO);
					break;
				}// End of Switch

				switch(Default_State){
					case(PUSH_PULL):
						GPIOB_OTYPER &= ~(0x01<<PIN_NO);
					break;

					case(OPEN_DRAIN):
						GPIOB_OTYPER |= (0x01<<PIN_NO);
					break

					case(PULL_UP):
						GPIOB_PUPDR &= ~(0x03<<2*PIN_NO);
						GPIOB_PUPDR   |=  (0x01<<2*PIN_NO);
					break;

					case(PULL_DOWN):
						GPIOB_PUPDR &= ~(0x03<<2*PIN_NO);
						GPIOB_PUPDR   &=  ~(0x02<<2*PIN_NO);
					break;

				}//End of Switch
	}

}

unsigned char GPIO_WritePin(char Port, unsigned int PIN_NO, unsigned int Data){
	unsigned char result;
	switch(Port){
		case('A'):
			if((GPIOA_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 1){
			     if(Data){GPIOA_ODR |= (1<<PIN_NO);}
			     else{GPIOA_ODR &= ~(1<<PIN_NO);}
				result = OK;
			}
			else{result = NOK;}
		break;

		case('B'):
			if((GPIOB_MODER & (0x01 << 2*PIN_NO))>> (2*PIN_NO)){
				 if(Data){GPIOB_ODR |= (1<<PIN_NO);}
				 else{GPIOB_ODR &= ~(1<<PIN_NO);}
				result = OK;
			}
			else{result = NOK;}
		break;
	}// End of Switch

	return result;
}

unsigned int GPIO_ReadPin(char PORT , unsigned int PIN_NO){
	unsigned int data;
	switch(PORT){
		case('A'):
			if((GPIOA_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 0){
				data = GPIOA_IDR &= (1<<PIN_NO);
				data = (data>>PIN_NO);
			}
			break;

		case('B'):
			if((GPIOB_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 0){
				data = GPIOB_IDR &= (1<<PIN_NO);
				data = (data>>PIN_NO);
			break;
	} // End of Switch
	return data;
}


