
// max , average , min , sum

#include <stdio.h>
int main() {    

    int num1, num2 , num3, max, avg, min, sum;
    
    printf("Enter Three Integers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // calculating sum
    sum = num1 + num2 +num3;
    avg = (num1 + num2 + num3)/3;

    
    max = num1 > num2 ? num1 : num2;
    max = num3 > max ? num3 : max; 

    min = num1 < num2 ? num1 : num2;
    min = num3 < max ? num3 : min;

    
    printf(" Sum:\n");
    printf(" %d \n ",sum);
    printf("Average:\n");
    printf(" %d \n ",avg);
    printf("Maximum:\n");
    printf(" %d \n ",max);
    printf(" Minimum:\n");
    printf(" %d \n ",min);
    
    return 0;
}

