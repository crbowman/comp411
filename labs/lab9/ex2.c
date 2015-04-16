#include <stdio.h>
#include <string.h>

main(){
  char names[20][15];
  int num = 0;
  char name[15];
  
  while(1){
    scanf("%s", name);
    if(strcmp(name, "END") == 0)
      break;
    else
      strcpy(names[num], name);
      num++;
  }
    
  bedtimestory(names, 0, num);
}

void bedtimestory(char words[20][15], int current, int number){
  if(current == 0){
    printf("A child couldn't sleep, so her mother told a story about a little %s,\n", words[current]);
    bedtimestory(words, current + 1, number - 1);
    printf("And then the child fell asleep.\n");
    return;
  }
  else if(number == 1) {
    print_tabs(current);
    printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", words[current - 1], words[current]);
    print_tabs(current + 1);
    printf("... who fell asleep.\n");
    print_tabs(current);
    printf("... and then the little %s fell asleep\n", words[current - 1]);
    return;
  }
  else {
    print_tabs(current);
    printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", words[current - 1], words[current]);
    bedtimestory(words, current + 1, number - 1);
    print_tabs(current);
    printf("... and then the little %s fell asleep\n", words[current - 1]);
    return;
  }
}

void print_tabs(unsigned int n){
  int i;
  for(i = 0; i < n; i++){
    printf("  ");
  }
  return;
}
