#include<stdio.h>

void knapsack(int p[],int w[],int n,int W ){
    int table[20][20];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){  //<= as we also make an extra column and row for 0s
            if(i==0||j==0){     // for first row or column values are 0
                table[i][j]=0;
            }
            else if(j<w[i]){
                table[i][j]=table[i-1][j];
            }
            else{
                if(table[i-1][j]>table[i-1][j-w[i]]+p[i]){
                    table[i][j]=table[i-1][j];
                }
                else{
                    table[i][j]=table[i-1][j-w[i]]+p[i];
                }
            }
        }
    }
    for (int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            printf(" %d ",table[i][j]);
        }
        printf("\n");
    }

printf("\nMaximum profit is : %d",table[n][W]);
}
void main(){
    int p[20],w[20],W,n;

    printf("Enter number of objects\n");
    scanf("%d",&n);
    printf("Enter capacity of knapsack\n");
    scanf("%d",&W);
    for (int i=1;i<=n;i++){
        printf("Enter weight and profit of object %d=",i);
        scanf("%d",&w[i]);
        scanf("%d",&p[i]);
    }
    knapsack(p,w,n,W);

}


