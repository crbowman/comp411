/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */


string_swap(char *one, char *two){
  int i;
  char tmp;
  for(i=0; i<LEN; i++){
    tmp = one[i];
    one[i] = two[i];
    two[i] = tmp;
  }
}

int string_compare(char a[], char b[]){
  int c = 0;
  
  while(a[c] == b[c]){
    if(a[c] == '\0' || b[c] == '\0'){
      break;
    }
    c++;
  }
  if(a[c] == '\0' && b[c] == '\0'){
    return 0;
  }
  else if(a[c] < b[c]){
    return -1;
  }
  else if(a[c] > b[c]){
    return 1;
  }
}


main()
{
 
  char Strings[NUM][LEN];
  int i, j, cmp;
  char temp[LEN];
 
  printf("Please enter %d strings, one per line:\n", NUM);
  
  for(i=0; i<NUM; i++){
    fgets(Strings[i], LEN, stdin);
  }

  puts("\nHere are the strings in the order you entered:");

  for(i=0; i<NUM; i++){
    printf("%s", Strings[i]);
  }  

  /* Bubble sort */


  for(i=0; i<NUM-1; i++){
    for(j=i+1; j<NUM; j++){
      cmp = string_compare(Strings[i], Strings[j]);
      if(cmp>0){
	string_swap(Strings[i], Strings[j]);
      }
    }
  }
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them 
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */

  
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  for(i=0; i<NUM; i++){
    printf("%s", Strings[i]);
  }
  

  return 0;
}


