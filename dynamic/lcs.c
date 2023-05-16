#include <stdio.h>
#include <string.h>
void main()
{
    char str1[] = "ABCBDAB";
    char str2[] = "BDCABA";
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    int m1, m2, i, j;
    int table[n1 + 1][n2 + 1];
    int dir[n1 + 1][n2 + 1]; // up=1,left=-1,diag=2

    for (i = 0; i < n1 + 1; i++)
    {
        for (j = 0; j < n2 + 1; j++)
        {
            table[i][j] = 0;
            dir[i][j] = 0;
        }
    }

    for (i = 1; i < n1 + 1; i++)
    {
        for (j = 1; j < n2 + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                dir[i][j] = 2;
            }
            else
            {
                m1 = table[i - 1][j];
                m2 = table[i][j - 1];
                if (m1 >= m2)
                {
                    table[i][j] = m1;
                    dir[i][j] = 1;
                }
                else
                {
                    table[i][j] = m2;
                    dir[i][j] = -1;
                }
            }
        }
    }

    for (i = 0; i < n1 + 1; i++)
    {
        for (j = 0; j < n2 + 1; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (i = 0; i < n1 + 1; i++)
    {
        for (j = 0; j < n2 + 1; j++)
        {
            printf("%d\t", dir[i][j]);
        }
        printf("\n");
    }

    printf("\nPath\n");
    i = n1;
    j = n2;

    while (i > 0 && j > 0)
    {
        if (dir[i][j] == 2)
        {
            //diagonal way
            printf("%c", str1[i - 1]);
            i = i - 1;
            j = j - 1;
        }
        else if (dir[i][j] == 1)
        {
            //going up
            i = i - 1;
        }
        else
        {
            //going left
            j = j - 1;
        }
    }
}