#include <stdio.h>
int main() {    
    int time, sec, min, hrs;
    
    printf("Enter Integer to Calculate Time:\n ");
    scanf("%d", &time);

    hrs = time / 3600;
    int reminder = time % 3600;
    min = reminder / 60 ;
    sec = reminder % 60;
    printf("Hours:%d Minutes:%d Seconds:%d", hrs, min, sec);
    return 0;
}

