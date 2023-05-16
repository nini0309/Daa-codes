#include <stdio.h>

void main()
{
    int n = 3, item[n], profit[n], weight[n];
    float p_w[n],  total_profit = 0, sol_v[n], temp;
    for (int i = 0; i < n; i++)
    {
        item[i] = i + 1;
        printf("Enter profit and weight for item%d:-\n", i + 1);
        scanf("%d%d", &profit[i], &weight[i]);
    }
    for (int i = 0; i < n; i++)
    {
        p_w[i] = (float)profit[i] / (float)weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p_w[j] < p_w[j + 1])
            {
                temp = p_w[j];
                p_w[j] = p_w[j + 1];
                p_w[j + 1] = temp;
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        sol_v[i] = 0;
    }
    int k = 0;
    int capacity = 20;
    float sack[capacity];

    while (capacity != 0)
    {
        if (weight[k] <= capacity)
        {
            sol_v[k] = 1;
            sack[k] = profit[k];
            total_profit += profit[k];
            capacity -= weight[k];
        }
        else if (weight[k] > capacity && sol_v[k] == 0 && capacity != 0)
        {
            sack[k] = capacity / (weight[k] * 1.0);
            total_profit += capacity * p_w[k] * 1.0;
            sol_v[k] = sack[k];
            capacity = 0;
        }
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (item[j] > item[j + 1])
            {
                temp = p_w[j];
                p_w[j] = p_w[j + 1];
                p_w[j + 1] = temp;
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
                temp = sol_v[j];
                sol_v[j] = sol_v[j + 1];
                sol_v[j + 1] = temp;
            }
        }
    }

    printf("\n");
    printf("Total profit=%.3f", total_profit);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t", sol_v[i]);
    }
}

// #include<stdio.h>


// void main(){
//     int n=3;
//     int profit[]={25,24,15};
//     int weight[]={18,15,10};
//     int item[]={1,2,3};
//     float p_w[n];
//     for(int i=0;i<n;i++){
//         p_w[i]=(float)profit[i]/(float)weight[i];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(p_w[j]<p_w[j+1]){
//                 float temp1=p_w[j];
//                 p_w[j]=p_w[j+1];
//                 p_w[j+1]=temp1;

//                 int temp2=profit[j];
//                 profit[j]=profit[j+1];
//                 profit[j+1]=temp2;

//                 int temp3=weight[j];
//                 weight[j]=weight[j+1];
//                 weight[j+1]=temp3;

//                 int temp4=item[j];
//                 item[j]=item[j+1];
//                 item[j+1]=temp4;
//             }
//         }
//     }


//     int capacity=20;
//     float sack[capacity],total=0,check[n];
//     int i=0;

//     for(int j=0;j<n;j++){
//         check[j]=0;
//     }
//     while(capacity!=0){
//         if(capacity>=weight[i]){
//             total+=profit[i];
//             sack[i]=weight[i];
//             capacity-=weight[i];
//             check[i]=1;
         
//         }
//         else if(capacity<weight[i] && check[i]==0 && capacity!=0){
//             sack[i]=capacity/(weight[i]*1.0);
//             total+=capacity*p_w[i]*1.0;
//             check[i]=sack[i];
//             capacity=0;
                       
//         }
//         i++;     
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(item[j]>item[j+1]){
//                 float temp1=p_w[j];
//                 p_w[j]=p_w[j+1];
//                 p_w[j+1]=temp1;

//                 float temp5=check[j];
//                 check[j]=check[j+1];
//                 check[j+1]=temp1;

//                 int temp2=profit[j];
//                 profit[j]=profit[j+1];
//                 profit[j+1]=temp2;

//                 int temp3=weight[j];
//                 weight[j]=weight[j+1];
//                 weight[j+1]=temp3;

//                 int temp4=item[j];
//                 item[j]=item[j+1];
//                 item[j+1]=temp4;
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         printf("%d\t%d\t%d\t%.2f\t%.2f\n",item[i],profit[i],weight[i],p_w[i],check[i]);
//     }
//     printf("Total = %.2f\n",total);
    
    
// }