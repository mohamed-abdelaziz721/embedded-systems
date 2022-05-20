
#include "GPIO.h"
#include "KEYPAD.h"
#include "SEVEN_SEGMENT.h"
#define GPIO_REG(PORT_ID,REG_ID) (*((unsigned int *)(PORT_ID+REG_ID)))
#define GPIO_SYSCFG_EXTICR1        GPIO_REG(0x40013800,0X08) //address of external interrupt configuration register 1
#define RCC_APB2ENR                GPIO_REG(0x40023800,0X44)
#define EXTI_IMR                   GPIO_REG(0x40013C00,0X00)
#define EXTI_FTSR                  GPIO_REG(0x40013C00,0X0C)
#define EXTI_PR                    GPIO_REG(0x40013C00,0X14)
#define NVIC_ISER0                 GPIO_REG(0xE000E100,0x00)
#define NVIC_ICER0                 GPIO_REG(0XE000E180,0x180)



unsigned char lookup[11] = {0x00,0x3F, 0x06, 0x5B, 0x4F, 0x66,
                       0x6D, 0x7D, 0x07, 0x7F, 0x6F};

unsigned int counter =0 ;



int main(void)
{
	RCC_APB2ENR |= (0x01 << 0xE);//enabling the bus that carry external interrupt
	GPIO_EnableClock(0);// enabling RCC AHB1ENR port A
	GPIO_EnableClock(1);// enabling RCC AHB1ENR port B
    for (int i=0;i<7;i++)
    {
		GPIO_Init(1, i, OUTPUT,PUSH_PULL);//make port B pins from 0 to 6 OUTPUT
    }

	GPIO_Init(0, 0, INPUT ,PULL_UP);//make port B pin 0  INPUT PULL UP
	GPIO_Init(0, 1, INPUT ,PULL_UP);//make port B pin 1  INPUT PULL UP




    GPIO_SYSCFG_EXTICR1 &=  ~(0x01<<0);//enabling system configration port B pin 0 as external interrupt0
    GPIO_SYSCFG_EXTICR1 &=  ~(0x0F<<4);//enabling system configration port B pin 1 as external interrupt1

    EXTI_IMR |=(0x01<<0); //Interrupt request from line zero is not masked
    EXTI_IMR |=(0x01<<1); //Interrupt request from line one is not masked

    EXTI_FTSR |=(0x01<<0);//Falling  edge trigger from line 0 enabled
    EXTI_FTSR |=(0x01<<1);//Falling  edge trigger from line 1 enabled

    NVIC_ISER0 =1<<6;// enable interrupt from nvic of line zero
    NVIC_ISER0 =1<<7;// enable interrupt from nvic of line one

    unsigned char localcount;
    while (1)
    {
		// Race condition ((ATOMIC FUnction)) 
        interrupt_disable();
        localcount= counter;
        interrupt_enable();
    	write_hex(lookup[localcount]);

    }


  return 0;
}
void increament()

{
	if (counter>9)
	{
		counter =1;
	}
	else
		counter ++;
	 EXTI_PR |=(0x01<<0);// falling the flag by software when the event arrives on the external interrupt line ودا بينزل ف اخر الفانكشن بتاعتك
}
void decreament()
{


	if (counter <2)
	{
		counter =10;
	}
	else
		counter --;


	 EXTI_PR |=(0x01<<1);// falling the flag by software when the event arrives on the external interrupt line ودا بينزل ف اخر الفانكشن بتاعتك
}


void interrupt_disable()
  {
	 NVIC_ICER0 =1<<6;// DISnable interrupt from nvic of line zero
	 NVIC_ICER0 =1<<7;// DISable interrupt from nvic of line ONE
  }
void interrupt_enable()
   {
	NVIC_ICER0 =~(1<<6);// DISnable interrupt from nvic of line zero
	NVIC_ICER0 =~(1<<7);// DISable interrupt from nvic of line ONE
   }









