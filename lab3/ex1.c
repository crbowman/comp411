/*  Example: C program to find area of a circle */

#include <stdio.h>

main()
{
  int n, x;
  
  printf("Please enter a number from 1 to 5: ");
  scanf("%d", &n);

  if(n<1 || n>5){
	printf("Number is not in the range from 1 to 5\n");
	return;
  }
  else{
	for(x=0; x<n; x++){
		printf("Hello World\n");	
  	};
  	return;
  }
}


