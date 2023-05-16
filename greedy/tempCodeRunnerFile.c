

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter the size of the universal set: ");
    scanf("%d", &n);

    int universalSet[n];
    printf("Enter the elements of the universal set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &universalSet[i]);

    int m;
    printf("Enter the number of subsets: ");
    scanf("%d", &m);

    int subsets[m][n];
    int subsetSizes[m];

    for (int i = 0; i < m; i++)
    {
        printf("Enter the size of subset %d: ", i+1);
        scanf("%d", &subsetSizes[i]);

        printf("Enter the elements of subset %d:\n", i+1);
        for (int j = 0; j < subsetSizes[i]; j++)
            scanf("%d", &subsets[i][j]);
    }


    printf("Selected subsets in the cover:\n");
    bool covered[n];
    for (int i = 0; i < n; i++)
        covered[i] = false;

    int selectedSubset[m];
    for (int i = 0; i < m; i++)
        selectedSubset[i] = 0;

    int maxUncoveredElements = 0;
    int maxSubsetIndex = -1;

    while (maxSubsetIndex != -2)
    {
        maxUncoveredElements = 0;
        maxSubsetIndex = -1;

        for (int i = 0; i < m; i++)
        {
            if (selectedSubset[i] != 0)
                continue;

            int uncoveredElements = 0;
            bool uniqueCovered[n];
            for (int j = 0; j < n; j++)
                uniqueCovered[j] = false;

            for (int j = 0; j < subsetSizes[i]; j++)
            {
                int element = subsets[i][j];

                if (!covered[element - 1] && !uniqueCovered[element - 1])
                {
                    uncoveredElements++;
                    uniqueCovered[element - 1] = true;
                }
            }

            if (uncoveredElements > maxUncoveredElements)
            {
                maxUncoveredElements = uncoveredElements;
                maxSubsetIndex = i;
            }
        }

        if (maxSubsetIndex != -1)
        {
            selectedSubset[maxSubsetIndex] = 1;

            for (int j = 0; j < subsetSizes[maxSubsetIndex]; j++)
            {
                int element = subsets[maxSubsetIndex][j];
                covered[element - 1] = true;
            }

            printf("Subset %d\n", maxSubsetIndex + 1);
        }
    }

    return 0;
}