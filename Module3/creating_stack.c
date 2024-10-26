#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int peek() {
    if(top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top];
}

int main() {
    int value;
    printf("Enter value 1 to push: ");
    scanf("%d", &value);
    push(value);
    printf("Enter value 2 to push: ");
    scanf("%d", &value);
    push(value);
    value = peek();
    printf("Peek value is: %d\n",value);
    value = pop();
    if (value != -1) {
        printf("Popped value: %d\n", value);
    }    
    return 0;
}