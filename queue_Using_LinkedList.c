#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node * next;
}Node;

Node* front = NULL;
Node* rear = NULL;


void display(){
    Node* ptr = front;
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    else{
        printf("Queue is : \n");
        while(ptr != NULL){
            printf("%d-->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void enqueue(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter the data of newNode : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newNode;
        rear = newNode;
       
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    display();
}

void dequeue(){
    Node* temp;
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    else{
        printf("Deleted element is %d ",front->data);
        temp = front;
        front  = front->next;
        free(temp);
    }
    display();
}


int main(){
    int choice;

    while(1){
    printf("\n1. Insert element to queue \n ");
    printf("2. Delete element from queue \n");
    printf("3.Display all element of queue \n");
    printf("4.Exit \n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);

        switch(choice){
            case 1 : enqueue();
                    break;
            case 2 : dequeue();
                    break;
            case 3 : display();
                    break;
            case 4 : exit(1);
                    break;
            default: printf("Enter Valid choice\n");
        }
    }   
}