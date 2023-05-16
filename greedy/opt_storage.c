#include<stdio.h>
void main()
{
    int tape[] = {1,2,3};
    int len[] = {5,10,3};
    int i,j,n=3,sum=0,temp,fsum=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(len[j] > len[j+1])
            {
                temp = len[j];
                len[j] = len[j+1];
                len[j+1] = temp;

                temp = tape[j];
                tape[j] = tape[j+1];
                tape[j+1] = temp;
            }
        }
    }
    // sum=len[0];
    printf("Optimal sequence is \n");
    for(i=0;i<n;i++)
    {
        printf("T%d  ",tape[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j>=0;j--)
        {
            sum = sum + len[j];
        }
        fsum = fsum + sum;
    }
    printf("\nTotal tape traversal is %d",fsum);
}