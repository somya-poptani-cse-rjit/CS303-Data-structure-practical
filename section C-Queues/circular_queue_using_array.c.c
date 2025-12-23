#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// enqueue operation
void enqueue(int value){
    if((rear + 1) % MAX == front){
        printf("Circular Queue Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    cq[rear] = value;
}

// dequeue operation
void dequeue(){
    if(front == -1){
        printf("Circular Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", cq[front]);
    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// display circular queue
void display(){
    if(front == -1){
        printf("Circular Queue is empty\n");
        return;
    }
    int i = front;
    while(1){
        printf("%d ", cq[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// main function
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Circular Queue elements: ");
    display();

    dequeue();

    printf("After dequeue: ");
    display();

    return 0;
}
