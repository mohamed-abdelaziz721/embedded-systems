#include "GPIO.h"

/**
 * @file main.c
 * @author mohamed abdelaziz (mohamed.ahmed997@eng-st.cu.edu.eg)
 * @brief Lab 7 
 * @version 0.1
 * @date 25-12-2021
 * 
 * Supervisors: Eng.Alaa Malik - Eng. Abdullah Darwish
 * 
 */



#define GPIO_REG(PORT_ID,REG_ID) (*((unsigned int *)(PORT_ID+REG_ID)))
#define GPIO_SYSCFG_EXTICR1        GPIO_REG(0x40013800,0X08) //address of external interrupt configuration register 1
#define RCC_APB2ENR                GPIO_REG(0x40023800,0X44)
#define EXTI_IMR                   GPIO_REG(0x40013C00,0X00)
#define EXTI_FTSR                  GPIO_REG(0x40013C00,0X0C)
#define EXTI_PR                    GPIO_REG(0x40013C00,0X14)
#define NVIC_ISER0                 GPIO_REG(0xE000E100,0x00)

void Exti0(void);

unsigned char state =0;

int main(void)
{

	GPIO_Init( PORTA , 0 , OUTPUT , PUSH_PULL);
	GPIO_Init( PORTB , 0 , INPUT , PULL_UP);
	
	// Enable APB bus (for external interrupt)
	RCC_APB2ENR |=(0x4000);
	// Enable port B pin 0 as external interrupt
    GPIO_SYSCFG_EXTICR1 |=  (0x01<<0);
	// Interrupt request from line zero
    EXTI_IMR |=(0x01<<0); 
	// Falling edge enabled trigger from line 0 
    EXTI_FTSR |=(0x01<<0);
	// Enable interrupt from NVIC
    NVIC_ISER0 =1<<6;

    while (1){}
  return 0;
}
void Exti0()
{
	if (state ==0){
		 GPIO_WritePin( PORTA,0,1 );
				 state =1;
	}
	else{
		GPIO_WritePin( PORTA ,0,0);
		 state =0;
	}
	// Setting the flag by software when the event arrives
	 EXTI_PR |=(0x01<<0);
	 
}






