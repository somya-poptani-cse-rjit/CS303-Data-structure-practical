#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node{
    int data;
    struct node* prev;
    struct node* next;
};

// traversal of doubly linked list
void traverse(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// insert at beginning
struct node* insertatfirst(struct node* head, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    return newnode;
}

// insert at end
struct node* insertatend(struct node* head, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        return newnode;
    }
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

// delete at first
struct node* deleteatfirst(struct node* head){
    struct node* temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

// delete by value
struct node* deletebyvalue(struct node* head, int value){
    struct node* temp = head;
    while(temp != NULL && temp->data != value)
        temp = temp->next;
    if(temp == NULL)
        return head;
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

// main function
int main(){
    struct node* head = NULL;

    head = insertatfirst(head, 10);
    head = insertatfirst(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 40);

    printf("Doubly Linked List: ");
    traverse(head);

    head = deleteatfirst(head);
    printf("After deleting first node: ");
    traverse(head);

    head = deletebyvalue(head, 30);
    printf("After deleting value 30: ");
    traverse(head);

    return 0;
}
