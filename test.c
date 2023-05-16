#include <stdio.h>
#define size 9
#define MAX 20

void main(){
    int coins[size] = { 1, 2, 5, 10, 20,50, 100, 200, 2000 };
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(coins[j]<coins[j+1]){
                int temp=coins[j];
                coins[j]=coins[j+1];
                coins[j+1]=temp;
            }
        }
    }
    int sol_v[10];
    int cost=500;
    int k=0;
    for(int i=0;i<size;i++){
        while(cost >= coins[i]){
            cost-=coins[i];
            sol_v[k]=coins[i];
            k++;
        }
    }
    for(int i=0;i<k;i++){
        printf("%d\t",sol_v[i]);
    }
 
}