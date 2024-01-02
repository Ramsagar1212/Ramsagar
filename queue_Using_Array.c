#include<stdio.h>
#include<stdlib.h>
#define MAX  10
void enqueue();
void dequeue();
int queue[MAX];
int rear = -1 , front = -1;



void display(){
    if(front == -1)
        printf("Queue is Empty\n");
    else{
        printf("Queue is : \n ");
        for(int i = front; i <= rear; i++){
            printf("%d--->", queue[i]);
        }
        printf("\n");
    }
}


void enqueue(){
    int newelement;
    if(rear == MAX -1){
        printf("Queue is Overflow\n");
        return;
    }
    else{
        if(front == -1){
            front = 0;
        }
            printf("Enter insert element in queue :");
            scanf("%d",&newelement);
            rear = rear + 1;
            queue[rear] = newelement;
    }
    display();
}

void dequeue(){
    if(front == -1 || front > rear ){
        printf("Queue is Underflow\n");
        return;
    }
    else{
        printf("Deleted element from queue is %d \n",queue[front]);
        front = front + 1;
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