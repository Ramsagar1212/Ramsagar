#include<stdio.h>
#include<stdlib.h>
void preorder();
void postorder();
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

Node* deleteNode(Node* root, int value){

    if(root == NULL) return root;

    if(root->data > value){
        root->left = deleteNode(root->left,value);
    }
    else if(root->data < value){
        root->right = deleteNode(root->right,value);
    }
    else{
        // if node is with only one child or no child
        if(root->left == NULL){
            Node* temp  = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // if node has two child
        Node* temp = indorderpred(root);
        root->data = temp->data;
        // delete inorder precedor
        root->left = deleteNode(root->left,temp->data);
       
    }

    return root;
}

int main(){
    Node* root = NULL;
    root = insertBST(root,40);
    insertBST(root,20);
    insertBST(root,70);
    insertBST(root,10);
    insertBST(root,30);
    insertBST(root,50);
    insertBST(root,80);
    insertBST(root,25);
    insertBST(root,35);
    insertBST(root,60);
    
    printf("Inorder Traversal : \n ");
    inorder(root);

    printf("\npreorder Traversal : \n ");
    preorder(root);

    printf("\npostorder Traversal : \n ");
    postorder(root);
  

    root = deleteNode(root,30);
    printf("\n \n after  deletion of 30 : \n");
    printf("Inorder Traversal : \n ");
    inorder(root);

    printf("\npreorder Traversal : \n ");
    preorder(root);

    root = deleteNode(root,40);
    printf("\n \n after  deletion of 40 : \n");
    
    printf("Inorder Traversal : \n ");
    inorder(root);

    printf("\npreorder Traversal : \n ");
    preorder(root);


    root = deleteNode(root,20);
    printf("\n \n after  deletion of 20 : \n");
    printf("Inorder Traversal : \n ");
    inorder(root);

    printf("\npreorder Traversal : \n ");
    preorder(root);
   
   
}