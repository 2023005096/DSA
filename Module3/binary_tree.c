#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
int data;
struct node* right;
struct node* left;
} *start;

int traverse(int data){
  struct node*newnode, *temp = start;
  while(1){
    if(temp -> data <= data){
      if(temp -> left == NULL){
        break;
      }else{
        temp = temp -> left;
      }      
    }else{
      if(temp -> right == NULL){
        break;
      }else{
        temp = temp -> right;
      }      
    }
  }
  return temp;
}

void insurt(int data){
  struct node* newnode,*temp,*pos;
  newnode = malloc(sizeof(struct node));
  if(start == NULL){
    newnode -> data = data;
    newnode -> right = newnode -> left = NULL;
    temp = start = newnode; 
  }else{
    newnode -> data = data;
    newnode -> right = newnode -> left = NULL;
    pos = traverse(data);
    if(pos -> data <= data){
      pos -> left = newnode;
    }else{
      pos -> right = newnode;
    }
  }
}

void display(){
  struct node *temp = start;

  
}

int main(void){
  int choice,m;
  while(1){
  printf("1.Enter data to insurt\n");
  //printf("Displat\n");
  printf("2.Exit\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      printf("Entr data : ");
      scanf("%d",&m);
      insurt(m);
      break;
    case 2:
      exit(0);
      break;
    default:
      printf("Invalid input");
      break;
  }
  }
}
