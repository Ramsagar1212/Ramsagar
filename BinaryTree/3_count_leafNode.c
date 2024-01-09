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

int count = 0;
int countnodes(Node* root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int leafcoount(Node* root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    else    
        return leafcoount(root->left) +  leafcoount(root->right);
}

int countInternalNode(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else    
        return 1 + countInternalNode(root->left) + countInternalNode(root->right);
}




int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Total Number of nodes in tree  = %d\n ",countnodes(root));
    
    printf("Total no. of leaf node : %d \n", leafcoount(root));

    printf("Total internal node : %d \n",countInternalNode(root));
    return 0;

}