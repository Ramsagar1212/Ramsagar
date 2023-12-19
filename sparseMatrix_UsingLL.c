#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int ri,ci,v;
    struct node* next;
}node;

int main(){
   
    int n,i,j,a[100][100],z=0,nz=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("\n Enter the elements: \n");
    for(i = 0; i<n ; i++){
        for(j = 0; j<n ; j++){
            scanf("%d",&a[i][j]);
        }
    }
        
    for(int i = 0;i<n; i++){
        for( int j=0;j<n;j++){
            if(a[i][j]==0)
                z++;
            else     
                nz++;
        }
    }

    if(z<nz){
        printf("\nIt is not a sparse matrix");
    }
    else{
        
        int spmatrix[nz][3];
        node *head = NULL;
        node *temp=NULL ,*newnode;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j] != 0 ){
                   if(head != NULL){
                    temp=(node*)malloc(sizeof(node));
                    temp->ri = i;
                    temp->ci = j;
                    temp->v = a[i][j];

                    temp->next = NULL;
                    head = temp;
                   }
                }
                else{
                    while (temp->next != NULL){
                        temp = temp->next;
                    }
                    newnode = (node*)malloc(sizeof(node));
                    newnode->ri = i;
                    newnode->ci = j;
                    newnode->v = a[i][j];

                    temp->next = newnode;
                    newnode->next = NULL;
                    head = temp;
                } 
            }
        }
        
        node*row,*col,*v;
        row = col = v = head;

        while(row != NULL){
            printf("%d ",row->ri);
            row = row->next
        }
        
    }
 
    return 0;
}