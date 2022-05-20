#ifndef GPIO_H
#define GPIO_H

/* Ports */
#define PORTA       'A'
#define PORTB       'B'

/* Pin Direction */
#define INPUT       0
#define OUTPUT      1
#define ALTERNATE   2
#define ANALOG      3

/* Input */
#define NO_PULL     0
#define PULL_UP     2
#define PULL_DOWN   4

/* Output */
#define PUSH_PULL   0
#define OPEN_DRAIN  1

/* Pin value */
#define LOW 0
#define HIGH 1

/* function state */
#define OK 0
#define NOK 1

void GPIO_Init(int port,char pin_no,char pin_dir, char state);
void GPIO_WritePin(int port, char pin_no, char Data);
unsigned char GPIO_ReadPin(int port, char pin_no);

void delay_ms(int ms);

#endif
