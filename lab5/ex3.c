/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for string functions */
#include <stdlib.h>

#define NUM 25 /* number of strings */
#define LEN 1000  /* max length of each string */

main()
{
  char* Strings[NUM];
  char temp[LEN];

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings, using fgets(). */

  int i, j, cmp;

  for (i=0; i<NUM; i++) {

    /* Read one line of input into a temp string that is long enough (LEN long) */

    fgets(temp, LEN, stdin);
    int length = strlen(temp);

    /* Allocate memory space for String[i] that is only large enough to copy the
       string just read into it.  Suppose the length of the string read into
       temp is "length", then you can use the following: */

    Strings[i] = malloc(length+1); /* Plus one for the NULL at end */
    strcpy(Strings[i], temp);
  }

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */

  for(i=0; i<NUM; i++){
    printf("%s", Strings[i]);
  }
  
  
  /* Bubble sort */
  for(i=0; i<NUM-1; i++){
    for(j=i+1; j<NUM; j++){
	cmp = strcmp(Strings[i], Strings[j]);
      if(cmp>0){
	char* tmp = Strings[i];
	Strings[i] = Strings[j];
	Strings[j] = tmp;
      }
    }
  }
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. */
  for(i=0; i<NUM; i++){
    printf("%s", Strings[i]);
  }

  /* Write a loop here to use free() to free up space allocated 
     for all of the strings above.  */

  for(i=0; i<NUM; i++){
    free(Strings[i]);
  }

  return 0;
}
