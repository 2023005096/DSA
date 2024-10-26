#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void create_list();
void display();
void insurt(int data);
void del();

struct node {
  int data;
  struct node *link;
} * start;

int main() {
  int choice, m;
  while (1) {
    printf("Enter your choice:\n");
    printf("1.Creation\n");
    printf("2.Display\n");
    printf("3.Insurtion\n");
    printf("4.Deletion\n");
    printf("5.exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      create_list();
      break;
    case 2:
      display();
      break;
    case 3:
      printf("Enter data : ");
      scanf("%d", &m);
      insurt(m);
      break;
    case 4:
      del();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  }
}

void create_list() {
  int inp, data;
  struct node *newnode, *temp;
  start = NULL;
  do {
    printf("If you want to enter new data press \"1\".\n");
    printf("If you want to exit print 0 : ");
    scanf("%d", &inp);
    if (inp == 0) {
      break;
    }
    printf("Enter data : ");
    scanf("%d", &data);
    newnode = (struct node *)malloc(sizeof(struct node));
    if (start == NULL) {
      start = temp = newnode;
    } else {
      temp->link = newnode;
      temp = newnode;
    }
    newnode->link = start;
    newnode->data = data;
  } while (inp != 0);
}

void display() {
  struct node *temp;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }
  temp = start;
  printf("%d ->", temp->data);
  while (temp->link != start) {
    printf("%d ->", temp->link->data);
    temp = temp->link;
  }
}

void insurt(int data) {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  temp = start;
  if (temp == NULL) {
    start = newnode;
    newnode->link = start;
  } else {
    while (temp->link != start) {
      temp = temp->link;
    }
    newnode->link = start;
    temp->link = newnode;
    temp = start;
  }
}

void del() {
  struct node *temp;
  temp = start;
  if (temp == NULL) {
    printf("Underflow");
  } else {
    while (temp->link->link != start) {
      temp = temp->link;
    }
    temp->link = start;
  }
}
