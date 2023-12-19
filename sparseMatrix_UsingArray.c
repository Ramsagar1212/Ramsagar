#include<stdio.h>
#include<stdlib.h>

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
       
        int spmatrix[nz][3],k =0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j] != 0 ){
                    spmatrix[k][0] = i;
                    spmatrix[k][1] = j;
                    spmatrix[k][2] = a[i][j];
                    k++;
                } 
            }
        }

        printf("\nSparse Matrix is : \n");
            for(int i = 0;i<nz; i++){
                for( int j=0;j<3;j++){
                    printf("%d ",spmatrix[i][j]);
                }
                printf("\n");
        }
    }
 
    return 0;
}