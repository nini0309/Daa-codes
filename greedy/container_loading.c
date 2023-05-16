#include<stdio.h>

void main(){
    int n=8;
    int weight[]={100,200,50,150,90,50,20,80};
    int containers[]={1,2,3,4,5,6,7,8};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(weight[j]>weight[j+1]){
                int temp=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp;

                temp=containers[j];
                containers[j]=containers[j+1];
                containers[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t%d\n",containers[i],weight[i]);
    }
    int sol_v[n],load[n];
    int max_capacity=400;
    int i=0,total=0;
    while(max_capacity!=0 && i<n){
        if(weight[i]<max_capacity){
            sol_v[i]=1;
            load[i]=containers[i];
            total+=weight[i];
            max_capacity-=weight[i];
        }
        i++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(containers[j]>containers[j+1]){
                int temp=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp;

                temp=containers[j];
                containers[j]=containers[j+1];
                containers[j+1]=temp;

                temp=sol_v[j];
                sol_v[j]=sol_v[j+1];
                sol_v[j+1]=temp;
            }
        }
    }
    printf("Total=%d\n",total);
    printf("Solution vector:-\n");
    for(int i=0;i<n;i++){
        printf("%d\t",sol_v[i]);
    }
}