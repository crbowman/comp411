/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

main()
{
  int i, f;

  do{
    printf("Enter a number: ");
    scanf("%d", &i);
    f = factorial(i);
    printf("%d! = %d\n", i, f);
  } while(i!=0);
  return;
}

int factorial(int i){
  if(i==0 || i==1){
    return 1;
  } 
  else{
    return i * factorial(i-1);
  }
}
