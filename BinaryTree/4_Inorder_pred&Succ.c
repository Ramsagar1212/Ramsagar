// find inoder predecessor & successor of a given BST

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left, *right;
}Node;

Node* createNode(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

Node* indorderpred(Node* root){
    root = root->left;
    while(root->right != NULL)
        root = root->right;
    
    return root;
}

Node* indorderSuccess(Node* root){
    root = root->right;
    while(root->left != NULL)
        root = root->left;
    
    return root;
}




Node* insertBST(Node* root, int value){
    if(root == NULL) 
        return createNode(value);
    // left side
    if(root->data > value) 
        root->left= insertBST(root->left,value);
    // right side
    else if(root->data < value) 
        root->right = insertBST(root->right,value); 

    return root;
}

int main(){
    Node* root = NULL;
    root = insertBST(root,6);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,1);
    insertBST(root,4);
    insertBST(root,5);
    insertBST(root,8);
    

    printf("Inorder Traversal : \n ");
    inorder(root);

    Node * pred = indorderpred(root);
    printf(" \ninorderpred of 6 is  %d ",pred->data);


    Node * succ = indorderSuccess(root);
    printf(" \ninorderpred of 6 is  %d ",succ->data);


}
