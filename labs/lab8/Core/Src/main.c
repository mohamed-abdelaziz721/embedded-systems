#include "SEVEN_SEGMENT.h"
#include "GPIO.h"

/**
 * @file main.c
 * @author mohamed abdelaziz (mohamed.ahmed997@eng-st.cu.edu.eg)
 * @brief Lab 8 
 * @version 0.1
 * @date 1-1-2022
 * 
 * Supervisors: Eng.Alaa Malik - Eng. Abdullah Darwish
 * 
 */


#define GPIO_REG(PORT_ID,REG_ID) (*((unsigned int *)(PORT_ID+REG_ID)))
#define RCC_APB1ENR GPIO_REG(0x40023800,0x40)  /* 					   APB Bus Address                                 			*/
#define GPIOA_AFRL GPIO_REG(0x40020000,0x20)   /* 					   Alternate Function Low Register Adress          			*/
#define USART_CR1 GPIO_REG(0x40004400,0x0c)	   /* 					   USART Control Register1 Adress                  			*/  	
#define USART_CR2 GPIO_REG(0x40004400,0x10)    /* 					   USART Control Register2 Adress                  			*/
#define USART_BRR GPIO_REG(0x40004400,0x08)    /* 					   USART Control Register Adress                   			*/
#define USART_SR GPIO_REG(0x40004400,0x00)     /* 					   USART Baud Rate Register Adress                 			*/
#define USART_DR GPIO_REG(0x40004400,0x04)     /* 					   USART Data Register  Adress                     			*/



void USART_configration(void);
void message(void);

int main(void) {
	GPIO_EnableClock(0);
	GPIO_Init(0,2,ALTERNATE_FUN,PUSH_PULL);     /* 					   Set Port A pin 2 to be output alternate_fun              */
	USART_configration();						/* 					   Setting the USART Configration                       	*/ 
 	message();                                  /* 					   Loop and Send message characters (Virtual Terminal)  	*/
	while(1) ; 
  	return 0;
}



void USART_configration(void){
	GPIOA_AFRL |=(0x7<<2 * 4);                  /*  					Alternate Function Selection of Port A pin 2             */
	RCC_APB1ENR|=(1<<17);                       /*  					HSE oscillator is stable                                 */
	USART_BRR=0x683;                            /*  					Control Register1 Mantissa and Fraction of USARTDIV      */
	USART_CR1 &=~(1<<15);						/*  					Control Register1 Oversampling by 16                     */
	USART_CR1 |=(1<<13);						/*  					Control Register1 USART enable                           */
	USART_CR1 &=~(1<<12);						/*  					Control Register1 Start bit, 8 Data bits, n Stop bit     */
	USART_CR1 |=(1<<3);							/*  					Control Register1 Transmitter is enabled                 */
	USART_CR1 &=~(1<<2);						/*  					Control Register1 Receiver is disabled                   */
	USART_CR2 &=~(0x3<<12);						/*  					Control Register1 1.5 Stop bit*/
}
void message(void){
	char x[]="HELLO WORLD !";
		for (int i =0; x[i]!='\0'; i++){
			USART_DR = x[i];
			while(((USART_SR>>6)& 0x01)==0);    
		}
}
