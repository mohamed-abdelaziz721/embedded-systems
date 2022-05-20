
#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f401xc.h"

//Write Result
#define OK  ((unsigned char)0)
#define NOK ((unsigned char)1)

//Mode Types
#define INPUT ((unsigned int)0x00)
#define OUTPUT ((unsigned int)0x01)
#define ALTERNATE_FUN ((unsigned int)0x02)
#define ANALOG ((unsigned int)0x03)

//Output Modes
#define PUSH_PULL ((unsigned int)0x00)
#define OPEN_DRAIN ((unsigned int)0x01)

//Input Modes
#define PULL_UP ((unsigned int)0x02)  
#define PULL_DOWN ((unsigned int)0x03)

void GPIO_Init(char Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State);
unsigned char GPIO_WritePin(char Port, unsigned int PIN_NO, unsigned int Data);
unsigned int GPIO_ReadPin(char Port, unsigned int PIN_NO);

char rgb_led_display(char);
void rgb_turn_off(void);


//RGB Led Colors

#define RED ((unsigned char)0x01)
#define GREEN ((unsigned char)0x02)
#define BLUE ((unsigned char)0x04)
#define YELLOW ((unsigned char)0x03)  
#define CYAN ((unsigned char)0x06)   
#define PURPLE ((unsigned char)0x05) 
#define WHITE ((unsigned char)0x07)   



#endif /* INC_GPIO_H_ */
