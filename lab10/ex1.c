#include <stdio.h>
#include <stdlib.h>

struct point {
  int x;
  int y;
  struct point * next;
};

int distance_squared(int x1, int y1, int x2, int y2){
  int delta_x = (x1 - x2);
  int delta_y = (y1 - y2);
  return (delta_x*delta_x) + (delta_y*delta_y);
}

int x;
int y;

void main(){
  int continue = 1;
  
  while(continue){
    scanf("%d%d", &x, &y);
    if (x==0 && y==0)
      break;
    else
      
    
  }
  
  
  

}

