#include<stdio.h>


int find_max(int arr[],int low,int high)
{
    int size=high-low+1;
    if(size==1)
    {
        return arr[high];
    }
    else if(size==2)
    {
        if(low>high)
        {
            return arr[low];
        }
        else
        {
            return arr[high];
        }
    }
    else
    {
        int max1,max2,max_final;
        int mid=(low+(high+1))/2;
        max1=find_max(arr,low,mid);
        max2=find_max(arr,mid+1,high);
        max_final=(max1>max2)?max1:max2;
        return max_final;

    }
}

int find_min(int arr[],int low,int high)
{
    int size=high-low+1;
    if(size==1)
    {
        return arr[high];
    }
    else if(size==2)
    {
        if(low<high)
        {
            return arr[low];
        }
        else
        {
            return arr[high];
        }
    }
    else
    {
        int min1,min2,min_final;
        int mid=(low+(high+1))/2;
        min1=find_min(arr,low,mid);
        min2=find_min(arr,mid+1,high);
        min_final=(min1<min2)?min1:min2;
        return min_final;

    }
}


void main()
{
    int arr[10];
    int n,i,max,min;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=find_max(arr,0,n-1);
    min=find_min(arr,0,n-1);
    printf("Maximum: %d\n",max);
    printf("Minimum: %d\n",min);
   
}