
#ifndef KEYPAD_H
#define KEYPAD_H

void KEYPAD_Init(void);
void KEYPAD_Manage(void);
unsigned char KEYPAD_GetKey(void);
void  KEYPAD_Callouts_KeyPressNotification(void);

#define RELEASED 0 ;
#define  PRESSED  1 ;


#endif /* KEYPAD_H */
