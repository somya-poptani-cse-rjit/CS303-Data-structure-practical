#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// push operation
void push(int value){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// pop operation
void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}

// peek operation
void peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// display stack
void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// main function
int main(){
    push(10);
    push(20);
    push(30);

    printf("Stack elements: ");
    display();

    peek();
    pop();

    printf("Stack after pop: ");
    display();

    return 0;
}
