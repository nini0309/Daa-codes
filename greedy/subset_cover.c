// #include <stdio.h>
// #include <stdbool.h>

// // Function to find the subset cover using greedy approach
// void subsetCover(int set[], int n, int subsets[][n], int m) {
//     bool selected[m];
//     for (int i = 0; i < m; i++) {
//         selected[i] = false;
//     }
    
//     int elements[n];
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         elements[count++] = set[i];
//     }
    
//     while (count > 0) {
//         int max = 0;
//         int maxIndex = -1;
//         for (int i = 0; i < m; i++) {
//             if (!selected[i]) {
//                 int tempCount = 0;
//                 for (int j = 0; j < n; j++) {
//                     if (subsets[i][j] != 0) {
//                         for (int k = 0; k < count; k++) {
//                             if (elements[k] == subsets[i][j]) {
//                                 tempCount++;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 if (tempCount > max) {
//                     max = tempCount;
//                     maxIndex = i;
//                 }
//             }
//         }
        
//         if (maxIndex != -1) {
//             printf("Subset %d: ", maxIndex + 1);
//             for (int j = 0; j < n; j++) {
//                 if (subsets[maxIndex][j] != 0) {
//                     printf("%d ", subsets[maxIndex][j]);
//                     for (int k = 0; k < count; k++) {
//                         if (elements[k] == subsets[maxIndex][j]) {
//                             for (int l = k; l < count - 1; l++) {
//                                 elements[l] = elements[l + 1];
//                             }
//                             count--;
//                             break;
//                         }
//                     }
//                 }
//             }
//             selected[maxIndex] = true;
//             printf("\n");
//         } else {
//             printf("No subset cover found.\n");
//             return;
//         }
//     }
// }

// // Driver code
// int main() {
//     int set[] = {1, 2, 3, 4, 5};
//     int subsets[][5] = {
//         {1, 2, 3},
//         {2, 4},
//         {3, 5},
//         {4, 5},
//         {5, 6},

//     };
//     int n = sizeof(set) / sizeof(set[0]);//no of sets
//     int m = sizeof(subsets) / sizeof(subsets[0]);//no of subsets
//     subsetCover(set, n, subsets, m);
//     return 0;
// }


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