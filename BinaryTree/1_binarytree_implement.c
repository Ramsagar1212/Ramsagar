#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left, *right;
}Node;

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;

    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}


Node* createNode(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

Node* insertleft(Node* root, int value){
    root->left = createNode(value);
    return root->left;
}


Node* insertright(Node* root, int value){
    root->right = createNode(value);
    return root->right;
}


int main(){
    Node* root = createNode(1);
    insertleft(root,2);
    insertright(root,3);

    insertleft(root->left,4);
    insertright(root->left,5);

    insertleft(root->right,6);
    insertright(root->right,7);

    printf("Inorder Traversal : \n ");
    inorder(root);

    printf("\npreorder Traversal : \n ");
    preorder(root);

    printf("\npostorder Traversal : \n ");
    postorder(root);



}