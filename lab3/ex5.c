
#include <stdio.h>

main()
{
  int i = 1, x;
  
  while(i != 0){
    printf("Number [1-100]: ?\n");
    scanf("%d", &i);

    if(i == 1){
      printf("Prime\n");
    }
    else if(i == 0){
    }
    else{
      for(x=2; x<=100; x++){
	if(i%x == 0 && i != x){
	  printf("Non-prime, divisible by %d\n", x);
	  x = 101;
	}
	else if(x == 100){
	  printf("Prime\n");
	}
      }
    }

  }
  
  printf("Done\n");
  return;
  
}


