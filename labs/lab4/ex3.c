/* Example: matrices represented by 2-dimensional arrays */

#include <stdio.h>

main()
{

  int A[3][3], B[3][3], C[3][3];
  int x, y, a;
  int i, j, k;

  puts("Please enter the values for A[0..2][0..2], one row per line:");

  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      scanf(" %d", &a);
      A[x][y] = a;
    }
  }

  puts("Please enter the values for B[0..2][0..2], one row per line:");

  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      scanf(" %d", &a);
      B[x][y] = a;
    }
  }

  printf("A=\n");
  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      printf("%6d", A[x][y]);
    }
    puts("");
  }

  printf("B=\n");
  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      printf("%6d", B[x][y]);
    }
    puts("");
  }

  
  /* multiply C = A.B: */
  
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      C[i][j] = 0;
      for (k =0; k < 3; k++)
        C[i][j] += B[i][k] * A[k][j];
    }
  
  printf("C=A.B=\n");
  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      printf("%6d", C[x][y]);
    }
    puts("");
  }

  /* multiply C = B.A: */
  
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      C[i][j] = 0;
      for (k =0; k < 3; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  
  printf("C=B.A=\n");
  for(y=0; y<3; y++){
    for(x=0; x<3; x++){
      printf("%6d", C[x][y]);
    }
    puts("");
  }
}
