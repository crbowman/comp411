/*  Example: C program to find area of a circle */

#include <stdio.h>

main()
{
  float x, y, z, sum, prod;
  
  printf("Enter three floating-point numbers:\n");
  scanf("%f%f%f", &x, &y, &z);

  sum = x + y + z;
  prod = x * y * z;

  printf("Sum is %.4f\n", sum);
  printf("Product is %.4f\n", prod);
  return;
  
}


