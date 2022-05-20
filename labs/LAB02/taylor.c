
// program to calculate :: e^x
#include <stdio.h>
 
/* 
* Returns approximate value of e^x
* using sum of first n terms of Taylor Series
*/ 

float exponential(int n, float x);
 
int main()
{
int n;
float x;
    printf("Enter the number of terms of taylor: ");
    scanf("%d",&n);

    printf("Enter x the power of the e^x: ");
    scanf("%f",&x);

    printf("e^%.0f = %f approximated by %d terms of taylor expantion", x , exponential(n, x), n);
    return 0;
}

float exponential(int n, float x)
{
    float sum = 1.0f;
 
    for (int i = n - 1; i > 0; --i )
        sum = 1 + x * sum / i;
 
    return sum;
}
