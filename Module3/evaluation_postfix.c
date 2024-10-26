#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
  if (top >= MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  top++;
  stack[top] = item;
}

int pop() {
  if (top < 0) {
    printf("Stack Underflow\n");
    return -1;
  }
  int item = stack[top];
  top--;
  return item;
}

int operators(int symbol) {
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
    return 1;
  }
  return 0;
}

int evaluate(int *exp, int length) {
  int operand1, operand2, result;
  for (int i = 0; i < length; i++) {
    int symbol = exp[i];
    if (!operators(symbol)) {
      push(symbol);
    } else {
      operand2 = pop();
      operand1 = pop();
      switch (symbol) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        if (operand2 == 0) {
          printf("Division by zero error\n");
          exit(1);
        }
        result = operand1 / operand2;
        break;
      }
      push(result);
    }
  }
  return pop();
}

int main() {
  int exp[] = {5, 6, 7, '+', '*', 8, '-'};
  int length = sizeof(exp) / sizeof(exp[0]);
  int result = evaluate(exp, length);
  printf("Result = %d\n", result);

  return 0;
}
