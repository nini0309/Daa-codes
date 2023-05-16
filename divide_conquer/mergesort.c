// Merge sort in C

#include <stdio.h>

void Merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;//i will iterate from lb to mid elements and j will iterate from mid+1 element to ub.
    //k is for another array and storing elements in sorted form.
    int b[50];
    while (i <= mid && j <= ub)
    {
        //comparing elements
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        //If there are any elements left where j is iterating
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        //If there are any elements left where i is iterating
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    // Copying array b in original array
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void mergesort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}
// Driver program
int main()
{
    // int size = 0;
    // printf("Enter size of array:-");
    // scanf("%d", &size);
    // int arr[size];
    // printf("Enter values:-\n");
    // for (int i = 0; i < size; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    int arr[]={4,8,2,6,1,7};
    int size=6;
    mergesort(arr, 0, size - 1);
    printf("Sorted array: \n");
    // printing array
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
