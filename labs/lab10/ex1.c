#include <stdio.h>
#include <stdlib.h>

int distance_squared(int x1, int y1, int x2, int y2){
  int delta_x = (x1 - x2);
  int delta_y = (y1 - y2);
  return (delta_x*delta_x) + (delta_y*delta_y);
}

struct node {
  int x;
  int y;
  struct node * next;
};

struct node *head = NULL;
struct node *curr = NULL;

struct node* create_list(int x, int y){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  if(NULL == ptr){
    printf("\n Node Creation Failed \n");
    return NULL;
  }
  ptr->x = x;
  ptr->y = y;
  ptr->next = NULL;

  head = curr = ptr;
  return ptr;
}

struct node* add_to_list(int x, int y){
  if (NULL == head){
    return (create_list(x, y));
  }

  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  if(NULL == ptr){
    printf("\n Node Creation Failed \n");
    return NULL;
  }
  ptr->x = x;
  ptr->y = y;
  ptr->next = NULL;

  curr->next =ptr;
  curr = ptr;

  return ptr;
}

void populate_list(){
  int x, y;
  int cont = 1;
  while(cont){
    scanf("%d%d", &x, &y);
    if (x==0 && y==0)
      break;
    add_to_list(x, y);
  }
}

 void print_distances(){
   struct node *ptr = head;
   while(ptr != NULL){
     printf("%d\n", distance_squared(ptr->x, ptr->y, 0, 0));
     ptr = ptr->next;
   }
   return;
 }

void main(){
  populate_list();
  print_distances();
}

