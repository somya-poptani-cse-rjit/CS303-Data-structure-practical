#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

// push operation
void push(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Stack Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// pop operation
void pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

// peek operation
void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// display stack
void display(){
    struct node* temp = top;
    if(temp == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
