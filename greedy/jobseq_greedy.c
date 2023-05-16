
#include<stdio.h>
#include <stdlib.h>

void main(){
    int n=4;
    int profit[]={50,15,10,25};
    int deadline[]={2,1,2,1};
    int item[]={1,2,3,4};
    int max=deadline[0];
    for(int i=0;i<n;i++){
        if(deadline[i]>max){
            max=deadline[i];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(profit[j]<profit[j+1]){

                int temp2=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp2;

                int temp3=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp3;

                int temp4=item[j];
                item[j]=item[j+1];
                item[j+1]=temp4;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("%d\t%d\t%d\n",item[i],profit[i],deadline[i]);
    // }

    int sol_v[max];
    for(int i=0;i<max;i++){
        sol_v[i]=0;
    }

    int j=0,total=0;
    for(int i=0;i<n;i++){
        while(j!=max){
            if(sol_v[abs(deadline[i]-1)]==0){
                sol_v[abs(deadline[i]-1)]=item[i];
                total+=profit[i];
                j++;
            }
            else{
                break;
            }
        }
    }

    printf("%d\n",total);
    for(int i=0;i<max;i++){
        printf("%d\t",sol_v[i]);
    }
 
}

// #include <stdio.h>
// void main()
// {
//     int n, i = 0, j = 0;
//     printf("ENTER NUMBER OF PROCESSES:-\n");
//     scanf("%d", &n);
//     int p[n], prft[n], deadline[n];
//     for (i = 0; i < n; i++)
//     {
//         p[i] = i + 1;
//         printf("ENTER PROFIT AND DEADLINE-\n");
//         scanf("%d%d", &prft[i], &deadline[i]);
//     }
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (prft[j] < prft[j + 1])
//             {
//                 int temp;
//                 temp = prft[j];
//                 prft[j] = prft[j + 1];
//                 prft[j + 1] = temp;
//                 temp = deadline[j];
//                 deadline[j] = deadline[j + 1];
//                 deadline[j + 1] = temp;
//                 temp = p[j];
//                 p[j] = p[j + 1];
//                 p[j + 1] = temp;
//             }
//         }
//     }
//     printf("Job\tProfit\tdeadline\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t%d\t%d\n", p[i], prft[i], deadline[i]);
//     }
//     int max = deadline[0];
//     for (i = 1; i < n; i++)
//     {
//         if (max < deadline[i])
//         {
//             max = deadline[i];
//         }
//     }
//     printf("\nMax=%d\n", max);
//     int sol_v[max];
//     for (i = 0; i < max; i++)
//     {
//         sol_v[i] = 0;
//     }
//     for (i = 0; i < n; i++)
//     {
//         int k = 1;
//         while (deadline[i] - k >= 0)
//         {
//             if (sol_v[deadline[i] - k] == 0)
//             {
//                 sol_v[deadline[i] - k] = p[i];
//                 break;
//             }
//             k++;
//         }
//     }
//     printf("SOLUTION VECTOR:-\n");
//     for (i = 0; i < max; i++)
//     {
//         printf("%d\t", sol_v[i]);
//     }
//     printf("\n");
// }