#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *link;
};
void printlist(struct node *temp) {
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->link;
  }
}
int main() {
  int inp, data;
  struct node *head, *newnode, *temp;
  head = NULL;
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
    if (head == NULL) {
      head = temp = newnode;
    } else {
      temp->link = newnode;
      temp = newnode;
    }
    newnode->link = NULL;
    newnode->data = data;
  } while (inp != 0);
  temp = head;
  printlist(temp);
}