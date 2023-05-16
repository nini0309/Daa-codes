#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int amt, n;
    printf("Enter the amount you want: ");
    scanf("%d", &amt);
    printf("Enter the number of denominations: ");
    scanf("%d", &n);

    int den[n];

    printf("Enter the denominations:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &den[i]);
    }

    // Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (den[i] > den[j])
            {
                int temp = den[i];
                den[i] = den[j];
                den[j] = temp;
            }
        }
    }

    int ans[n][amt + 1];

    //first row --> 
    for (int i = 0; i <= amt; i++)
    {
        ans[0][i] = i;
    }
    

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            if (j < den[i])
            {
                ans[i][j] = ans[i - 1][j];
            }
            else
            {
                ans[i][j] = min(ans[i][j - den[i]] + 1, ans[i - 1][j]);
            }
        }
    }

    printf("\nDenomination\t");
    for (int i = 0; i <= amt; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", den[i]);
        for (int j = 0; j <= amt; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }

    int vector[n];

    for (int i = 0; i < n; i++)
    {
        vector[i] = 0;
    }

    int row = n - 1;
    while (amt > 0 && row >= 0)
    {
        if (den[row] <= amt && ans[row][amt] - ans[row][amt - den[row]] == 1)
        {
            vector[row]++;
            amt -= den[row];
        }
        else
        {
            row--;
        }
    }

    printf("\nNo of coins needed:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", den[i], vector[i]);
    }

    return 0;
}