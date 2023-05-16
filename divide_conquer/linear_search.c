#include <stdio.h>

int linearsearch(int s,int l,int arr[],int val){
    if(s>l){
        printf("Value not found\n");
        return -1;
    }
    else if(arr[s]==val){
        printf("Value found at index %d\n",s);
        return s;
    }
    else{
        return linearsearch(s+1,l,arr,val);
    }
}

int binarysearch(int s,int l,int arr[],int x){
    if(s<=l){

    int mid=(s+l)/2;
    if(x==arr[mid]){
        printf("Value found at index %d\n",mid);
        return mid;
    }
    else if(x>arr[mid]){
        return binarysearch(mid+1,l,arr,x);
    }
    else{
        return binarysearch(s,mid+1,arr,x);
    }
    }
    printf("Value not found\n ");
    return -1;
}

void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


void main(){
    int n=0;
    printf("Enter no of elements:-\t");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int val=0;
    printf("Enter element to be searched:");
    scanf("%d",&val);
    // int result=linearsearch(0,n-1,arr,val);
    sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    int r=binarysearch(0,n-1,arr,val);

    
}
