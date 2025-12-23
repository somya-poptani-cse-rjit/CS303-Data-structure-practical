#include <stdio.h>
#include <stdlib.h>

// BST node
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// create new node
struct node* newnode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// insert operation
struct node* insert(struct node* root, int value){
    if(root == NULL)
        return newnode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// search operation
int search(struct node* root, int key){
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    if(key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// inorder traversal
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// main
int main(){
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder Traversal: ");
    inorder(root);

    int key = 40;
    if(search(root, key))
        printf("\n%d found in BST", key);
    else
        printf("\n%d not found in BST", key);

    return 0;
}
