#include "GPIO.h"
#include"GPIO_registers.h"

#define PUPD_MASK   0x03
#define PUPD_SHIFT  0x01
#define OTYPE_MASK  0x01

void GPIO_Init(int Port, char pin_no, char Direction, char state)
{
    Port -= 'A'; //   User enters 'A' or 'B' --> *LookUp[0][reg] or * LookUp[1][reg]

    *LookUp[Port][CLOCK]|= 1<<Port; // Enable Clock
    
    *LookUp[Port][MODER] &= ~(0X03 << (2 * pin_no));    
    *LookUp[Port][MODER] |= (Direction << (2 * pin_no));

    /*  case input User enters: NO_PULL (0) or PULL_UP (2) or PULL_DOWN (4)  */
    /*  state is shifted by 1 to make the value 0 ,1 & 2  (First bit is for otype)  */
    *LookUp[Port][PUPDR] &= ~(0X03 << (2 * pin_no));
    *LookUp[Port][PUPDR] |= (( (state >> PUPD_SHIFT) & PUPD_MASK) << (2 * pin_no));
    
    /*  case output User enters: PUSH_PULL(0) or OPEN_DRAIN(1)  */
    /*  state is anded by 1 to clear the pupdr value  */
    *LookUp[Port][OTYPER]&=~(0x01 << pin_no);
    *LookUp[Port][OTYPER]|= ((state & OTYPE_MASK)<< pin_no);
}

void GPIO_WritePin(int Port, char pin_no, char Data)
{
    Port -= 'A';
    if (Data)
    {
        *LookUp[Port][ODR] |= (0x01<<pin_no);
    }
    else
    {
        *LookUp[Port][ODR] &= ~(0x01 << pin_no);
    }
}


unsigned char GPIO_ReadPin(int Port, char pin_no)
{
    Port-='A';
    return (*LookUp[Port][IDR] >> (pin_no)) & 0X01;
}



void delay_ms(int ms)
{
	for(int i=0;i<ms*1000;i++);
}
