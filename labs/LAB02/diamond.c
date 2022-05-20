/*
* This program take user input for the number of rows of a diamond shape
*/

#include <stdio.h>
int main()
{
  int n, c, k;

  printf("Enter number of rows\n");
  scanf("%d", &n);

  // Loop for the upper half of the diamond shape
  for (k = 1; k <= n; k++)
  {
    for (c = 1; c <= n-k; c++)
      printf(" ");

    for (c = 1; c <= 2*k-1; c++)
      printf("*");

    printf("\n");
  }

  // Loop for the upper half of the diamond shape :: with lower rows  = upper rows - 1
  for (k = 1; k <= n - 1; k++)
  {
    for (c = 1; c <= k; c++)
      printf(" ");

    for (c = 1 ; c <= 2*(n-k)-1; c++)
      printf("*");

    printf("\n");
  }

  return 0;
}