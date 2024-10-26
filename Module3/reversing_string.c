#include <stdio.h>
#include <string.h>
#define max 100
int top, stack[max];

void push(char x) {
  if (top == max - 1) {
    printf("Stack overflow");
  } else {
    stack[++top] = x;
  }
}

void pop() { printf("%c", stack[top--]); }

int main() {
  char str[] = "MY NAME IS PRANAY";
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    push(str[i]);
  }
  for (int i = 0; i < len; i++) {
    pop();
  }
}