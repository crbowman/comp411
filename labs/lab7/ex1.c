#include <stdio.h>

main(){
  char MAGIC_NUMBER[4];
  int ROWS, COLUMNS, PPM_MAX; 

  scanf("%s", MAGIC_NUMBER);
  scanf("%d%d%d", &ROWS, &COLUMNS, &PPM_MAX);
  
  puts("P2");
  printf("%d\n%d\n", ROWS, COLUMNS);
  puts("255");

  int i;
  int r, g, b, gray;
  
  for(i=0; i<(ROWS*COLUMNS); i++){
    scanf("%d%d%d", &r, &g, &b);
    gray = (((r + b + g) * 255) / (3 * PPM_MAX));
    printf("%d\n", gray);    
  }

}
