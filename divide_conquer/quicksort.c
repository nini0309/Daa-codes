#include<stdio.h>

void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int Partition(int a[],int lb,int ub){
    int pivot=a[lb],start=lb,end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a,start,end);
        }
    }
    swap(a,lb,end);
    return end;
}


void Quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=Partition(arr,lb,ub);
        Quicksort(arr,lb,loc-1);
        Quicksort(arr,loc+1,ub);
    }
}


void main(){
    int arr[]={5,9,10,15,3,6};
    int size=6;
    printf("Original Array:\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    Quicksort(arr,0,size-1);
    printf("\n");
    printf("Sorted Array:\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}