#include <stdio.h>
#include <string.h>


int myAtoi(char *str)
{
  int res = 0; // Initialize result
  int i;
  // Iterate through all characters of input string and update result
  for (i = 0; str[i] != '\0'; ++i){
    res = res*10 + str[i] - '0';
  }
  // return result.
  return res;
}
 
int a_to_i(char *a){
  int c, tmp;
  int exit = 0;
  int i = 0;
  for (c = 0; exit != 1; c++){
    if(a[c] == '\0'){
      exit = 1;
      break;
    }
    tmp = (int)a[c];
    i = i*10 + tmp;
  }
  return i;
}

main(){

  char str[100];
  printf("Please enter a string representing an integer\n");
  fgets(str, 100, stdin);
  int i = myAtoi(str);
  printf("%d\n", i);
   

}
