#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node{
    int data;
    struct node* next;
};

// traversal of linked list
void traverse(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// insert at beginning
struct node* insertatfirst(struct node* head, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    return newnode;
}

// insert at end
struct node* insertatend(struct node* head, int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL)
        return newnode;
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

// delete at first
struct node* deleteatfirst(struct node* head){
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// delete by value
struct node* deletebyvalue(struct node* head, int value){
    struct node* p = head;
    struct node* q = head->next;
    while(q != NULL && q->data != value){
        p = q;
        q = q->next;
    }
    if(q != NULL){
        p->next = q->next;
        free(q);
    }
    return head;
}

// main function
int main(){
    struct node* head = NULL;

    head = insertatfirst(head, 10);
    head = insertatfirst(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 40);

    printf("Linked List: ");
    traverse(head);

    head = deleteatfirst(head);
    printf("After deleting first node: ");
    traverse(head);

    head = deletebyvalue(head, 30);
    printf("After deleting value 30: ");
    traverse(head);

    return 0;
}
