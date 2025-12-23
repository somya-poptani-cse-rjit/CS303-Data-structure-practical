#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// enqueue operation
void enqueue(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Queue Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if(rear == NULL){
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

// dequeue operation
void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Deleted element: %d\n", front->data);
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(temp);
}

// display queue
void display(){
    struct node* temp = front;
    if(temp == NULL){
        printf("Queue is empty\n");
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
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue elements: ");
    display();

    dequeue();

    printf("Queue after dequeue: ");
    display();

    return 0;
}
