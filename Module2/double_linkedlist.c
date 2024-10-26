 #include<stdio.h>
 #include<stdlib.h>
 #include<malloc.h>

void create_list();
void display();
void addatbeg(int data);
void addatend(int data);
void addafter(int data, int pos);
void delbeg();
void delend();
void del(int data);
void countnodes();
void reverse();

struct node{
int data;
struct node*prev;
struct node*link;
} *start;

int main(void) {
  int choice, m, n;
  while (1) {
    printf("Enter your choice:\n");
    printf("1.Creation\n");
    printf("2.Display\n");
    printf("3.Add at beginning\n");
    printf("4.Add at ending\n");
    printf("5.Add after\n");
    printf("6.Deleting at beginning\n");
    printf("7.Deleting at ending\n");
    printf("8.Deleting the element\n");
    printf("9.Count number of nodes\n");
    printf("10.Reverse the linked list\n");
    printf("11.exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      create_list();
      break;
    case 2:
      display();
      break;
    case 3:
      printf("Enter the data to add:");
      scanf("%d", &m);
      addatbeg(m);
      break;
    case 4:
      printf("Enter the data to add:");
      scanf("%d", &n);
      addatend(n);
      break;
    case 5:
      printf("Enter the data: ");
      scanf("%d", &m);
      printf("Enter the position: ");
      scanf("%d", &n);
      addafter(m, n);
      break;
    case 6:
      delbeg();
      break;
    case 7:
      delend();
      break;
    case 8:
      printf("Enter the data to delete:");
      scanf("%d", &m);
      del(m);
      break;
    case 9:
      countnodes();
      break;
    case 10:
      reverse();
      break;
    case 11:
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
      newnode -> prev = NULL;
    } else {
      temp->link = newnode;
      newnode -> prev = temp;
      temp = newnode;
    }
    newnode->link = NULL;
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
  while (temp != NULL) {
    printf("%d ->", temp->data);
    temp = temp->link;
  }
}

void addatbeg(int data) {
  struct node *newnode;
  newnode = malloc(sizeof(struct node));
  newnode->data = data;
  newnode->link = start;
  newnode -> prev = NULL;
  start = newnode;
}

void addatend(int data) {
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  temp = start;
  if (temp == NULL) {
    start = newnode;
    newnode->link = NULL;
    newnode -> prev = NULL;
  } else {
    while (temp->link != NULL) {
      temp = temp->link;
    }
    newnode->link = NULL;
    temp->link = newnode;
    newnode -> prev = temp;
    temp = start;
  }
}
void addafter(int data, int pos) {
  struct node *newnode, *temp;
  int i;
  temp = start;
  for (i = 0; i < pos; i++) {
    temp = temp->link;
    if (temp == NULL) {
      printf("There are less than %d elements", pos);
      exit(0);
    }
  }
  newnode = malloc(sizeof(struct node));
  newnode->link = temp->link;
  newnode -> prev = temp;
  temp -> link -> prev = newnode;
  newnode->data = data;
  temp->link = newnode;
}

void delbeg() {
  struct node *temp;
  temp = start;
  if (temp == NULL) {
    printf("Underflow");
  } else {
    start = temp->link;
    start -> prev = NULL;
    free(temp);
  }
}

void delend() {
  struct node *temp;
  temp = start;
  if (temp == NULL) {
    printf("Underflow");
  } else {
    while (temp->link->link != NULL) {
      temp = temp->link;
    }
    temp->link = NULL;
  }
}

void del(int data) {
    struct node *temp;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start->data == data) {
        temp = start;
        start = start->link;
        if (start != NULL) {
            start->prev = NULL; 
        }
        free(temp);
        return;
    }
    temp = start;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->link != NULL) { 
                temp->link->prev = temp->prev;
            }
            if (temp->prev != NULL) { 
                temp->prev->link = temp->link;
            }
            free(temp);
            return;
        }
        temp = temp->link;
    }
    printf("Element not found\n");
}


void countnodes()
{
  struct node *temp;
  int count=0;
  temp=start;
  while(temp!=NULL)
      {
          temp=temp->link;
          count++;
          }
  printf("Number of nodes are = %d\n",count);
}

void reverse()
{
    struct node *temp,*current = start;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->link;
        current->link = temp;
        current = current->prev; 
    }
    if (temp != NULL) {
        start = temp->prev;
    }
}