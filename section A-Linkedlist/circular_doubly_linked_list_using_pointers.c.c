#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

// traversal of circular doubly linked list
void traversal(struct node* head){
    if(head == NULL)
        return;
    struct node* temp = head;
    do{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("(back to head)\n");
}

// insertion at end
struct node* insertatend(struct node* head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }

    struct node* last = head->prev;
    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;
    return head;
}
// deletion of a node by value
struct node* deletenode(struct node* head, int value){
    if(head == NULL)
        return NULL;
    struct node* temp = head;
    do{
        if(temp->data == value){
            if(temp->next == temp){
                free(temp);
                return NULL;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if(temp == head)
                head = temp->next;
            free(temp);
            return head;
        }
        temp = temp->next;
    }while(temp != head);
    printf("Value not found\n");
    return head;
}
// main function
int main(){
    struct node* head = NULL;
    printf("Insert at end:\n");
    head = insertatend(head, 10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    traversal(head);
    printf("After deleting node 20:\n");
    head = deletenode(head, 20);
    traversal(head);
    return 0;
}
