// simple queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int arrqueue[MAX];
int front = -1;
int rear = -1;
void insurt(int value){
    if(rear == MAX - 1){
        printf("overflow.\n");
    }
    else if(rear == -1 && front == -1){
        rear = 0;
        front = 0;
    }else{
        rear = rear + 1;
    }
    arrqueue[rear] = value;
}
void del(){
    if(front == -1){
        printf("Underflow.\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front += 1;

    }
}
void print(int temp){
  if(temp == -1){
      printf("Underflow\n");
  }else{
      while(temp<=rear){
          printf("%d ",arrqueue[temp]);
          temp += 1;
      }
      printf("\n");
    }
}
int main() {
    int choice,value,temp;
    while(1){
    printf("Enter your choice,\n");
    printf("1.Insurt an element.\n");
    printf("2.Display.\n");
    printf("3.Delete an element.\n");
    printf("4.Exit.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter a value to insurt : ");
        scanf("%d",&value);
        insurt(value);
        break;
        case 2:
        print(front);
        break;
        case 3:
        del();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("Invaid input.\n");
        break;
    }
  }
  print(front);
}