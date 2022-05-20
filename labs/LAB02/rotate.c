
/* Program perform generic rotate right and rotate left
* User input 8 bit number x - number of rotate cycles n and rotate option 0
* the program print the rotate value of x n times based on the value of o (ROTATE rIGHT OR lEFT)
*/

#include <stdio.h>
/* This make sure that the intger is 8 bits only */
#define INT_SIZE sizeof(int)        // Size of int in bytes
#define INT_BITS INT_SIZE * 8 - 1   // Size of int in bits - 1

/* Function declarations */
int rotateLeft(int num, unsigned int rotation);
int rotateRight(int num, unsigned int rotation);


int main(){

int num, rotation_direction;
unsigned int rotation;

    /* Input number from user */
    printf("Enter a number: ");
    scanf("%d", &num);

    /* Input number of rotation */
    printf("Enter number of rotation: ");
    scanf("%u", &rotation);

    printf("Enter 0 for left rotation or Enter 1 for right rotation: ");
    scanf("%d", &rotation_direction);


    /* Print rotated number */
    if (rotation_direction == 0){
        printf("%d left rotated %u times = %d\n\n",  num, rotation, rotateLeft(num, rotation));
    }else if (rotation_direction == 1){
        printf("%d right rotated %u times = %d\n", num, rotation, rotateRight(num, rotation));
    }else{
        printf("Input is not correct\n");
        printf("Program exit...");
    }
    
    return 0;
}



int rotateLeft(int num, unsigned int rotation)
{
    int DROPPED_MSB;
    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get MSB of num before it gets dropped
        DROPPED_MSB = (num >> INT_BITS) & 1; 

        // Left rotate num by 1 and 
        // Set its dropped MSB as new LSB
        num = (num << 1) | DROPPED_MSB;
    }

    return num;
}



int rotateRight(int num, unsigned int rotation)
{
    int DROPPED_LSB;
    // Loop till rotation becomes 0
    while(rotation--)
    {
        // Get LSB of num before it gets dropped
        DROPPED_LSB = num & 1;

        // Right shift num by 1 and 
        // Clear its MSB
        num = (num >> 1) & (~(1 << INT_BITS));

        // Set its dropped LSB as new MSB
        num = num | (DROPPED_LSB << INT_BITS);
    }

    return num;
}




















    