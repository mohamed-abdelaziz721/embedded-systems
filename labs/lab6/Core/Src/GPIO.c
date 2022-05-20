
#include "GPIO.h"

/**
 * @file main.c
 * @author mohamed abdelaziz (mohamed.ahmed997@eng-st.cu.edu.eg)
 * @brief Lab 6 - Assignment 
 * @version 0.1
 * @date 18-12-2021
 * 
 * Supervisors: Eng.Alaa Malik - Eng. Abdullah Darwish
 */


#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

/* MACROS */
#define GPIOA_ADRESS (0X40020000)
#define GPIOB_ADRESS (0X40020400)
#define GPIO_REG(PORT_ID,REG_ID) (*((unsigned int *)(PORT_ID+REG_ID)))unsigned int port_ad[2]={GPIOA_ADRESS , GPIOB_ADRESS};
#define GPIO_IDR(ID)  GPIO_REG(port_ad[ID],0x10)
#define GPIO_ODR(ID)  GPIO_REG(port_ad[ID],0x14)
#define GPIO_BSRR(ID)  GPIO_REG(port_ad[ID],0x18)
#define GPIO_LCRR(ID)  GPIO_REG(port_ad[ID],0x1C)
#define GPIO_AFRL(ID)  GPIO_REG(port_ad[ID],0x20)
#define GPIO_AFRH(ID)  GPIO_REG(port_ad[ID],0x24)
#define GPIO_MODER(ID)  GPIO_REG(port_ad[ID],0x00)
#define GPIO_TYPER(ID)  GPIO_REG(port_ad[ID],0x04)
#define GPIO_PUPDR(ID)  GPIO_REG(port_ad[ID],0x0C)
#define GPIO_OSPEEDR(ID)  GPIO_REG(port_ad[ID],0x08)


void GPIO_EnableClock(unsigned char Port_id){
    if (Port_id == 0){
  	 GPIO_REG(0x40023800,0x30) |= (0x01 << 0);
    }
    else if(Port_id == 1){
  	 GPIO_REG(0x40023800,0x30) |= (0x01 << 1);
    };
}

void GPIO_Init(unsigned char port_id, unsigned char PinNum, unsigned char PinMode,unsigned char DefaultState){
    /* 
    * Configure pin direction using moder register
	  * configure mode of the bin (input - output----)
    */

	 GPIO_MODER(port_id) &= ~(0x03 << 2 * PinNum);
	 GPIO_MODER(port_id) |= PinMode << 2 * PinNum;

	 GPIO_TYPER(port_id) &= ~(1 << PinNum);
	 GPIO_TYPER(port_id) |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

   GPIO_PUPDR(port_id) &= ~(0x03 << 2 * PinNum);
	 GPIO_PUPDR(port_id) |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);

}

unsigned char GPIO_WritePin(unsigned char port_id, unsigned char PinNum, unsigned char Data){
  unsigned char result;
    if (((GPIO_MODER(port_id) & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1){
      if (Data){
      	GPIO_ODR(port_id) |= (1 << PinNum);
      }
      else{
      	GPIO_ODR(port_id) &= ~(1 << PinNum);
      }
      result = OK;
    }
    else{
      result = NOK;
    }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char port_id, unsigned char PinNum){
  unsigned char data=0;
  data = (((GPIO_IDR(port_id)) & (1 << PinNum)) >> PinNum);
  return data;
}
