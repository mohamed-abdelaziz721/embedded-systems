#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

/**
 * @file main.c
 * @author mohamed abdelaziz (mohamed.ahmed997@eng-st.cu.edu.eg)
 * @brief Lab 4
 * @version 0.1
 * @date 25-12-2021
 * 
 * Supervisors: Eng.Alaa Malik - Eng. Abdullah Darwish
 * 
 */

int main(void) {
	GPIO_init('A', 0 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 1 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 2 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 3 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 4 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 5 , OUTPUT, PUSH_PULL);
	GPIO_init('A', 6 , OUTPUT, PUSH_PULL);

	unsigned char hex_numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	while (1){
		/* Counter Loop */ 
		for(int j=0; j<10; j++){
			/* Loop over port A pins */
			for(int i=0; i<7; i++){
				if(hex_numbers[j] & (0x01<<i)){
					GPIO_writePin('A', i , 1);
				}
				else{
					GPIO_writePin('A', i , 0);
				}
			}
			/* delay for 500 ms */
			for (int i = 0; i < (500*1000); i++){}
		}
  }
  return 0;
}


