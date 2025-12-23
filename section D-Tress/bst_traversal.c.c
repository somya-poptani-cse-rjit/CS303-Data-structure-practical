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

// insert into BST
struct node* insert(struct node* root, int value){
    if(root == NULL)
        return newnode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// inorder traversal
void inorder(struct node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// preorder traversal
void preorder(struct node* root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// postorder traversal
void postorder(struct node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    // given preorder traversal
    int preorderArr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = 7;

    struct node* root = NULL;

    // build BST using preorder
    for(int i = 0; i < n; i++)
        root = insert(root, preorderArr[i]);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
