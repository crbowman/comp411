
#include <stdio.h>

unsigned int fibonacci(unsigned int n){
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (fibonacci(n-1) + fibonacci(n-2));
}

main(){
  int n, o;
  do {
      scanf("%d", &n);
      o = fibonacci(n);
      printf("%u\n", o);
  } while (n !=0);

}
