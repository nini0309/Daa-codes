#include <stdio.h>

// Define constants for TRUE and FALSE values
#define TRUE 1
#define FALSE 0

int inc[50], weight[50], sum, n;

// Check if the current partial solution is promising
int promising(int i, int wt, int total) {
    // Check if adding the remaining elements would be enough to meet the sum requirement
    return (((wt + total) >= sum) && ((wt == sum) || (wt + weight[i + 1] <= sum)));
}

// Recursive function to find the sum subset using backtracking
void sumset(int i, int wt, int total) {
    int j;
    // Check if the current partial solution is promising
    if (promising(i, wt, total)) {
        // If we have reached the target sum, print the solution
        if (wt == sum) {
            printf("\n{\t");
            for (j = 0; j <= i; j++)
                if (inc[j])
                    printf("%d\t", weight[j]);
            printf("}\n");
        } else {
            // Include the next element and continue the search
            inc[i + 1] = TRUE;
            sumset(i + 1, wt + weight[i + 1], total - weight[i + 1]);
            // Exclude the next element and continue the search
            inc[i + 1] = FALSE;
            sumset(i + 1, wt, total - weight[i + 1]);
        }
    }
}

int main() {
    int i, j, n, temp, total = 0;
    printf("\nEnter how many numbers:\n");
    scanf("%d", &n);
    printf("\nEnter %d numbers to the set:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        total += weight[i];
    }
    printf("\nInput the sum value to create a sub set:\n");
    scanf("%d", &sum);
    // Sort the input set in ascending order
    for (i = 0; i <= n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (weight[j] > weight[j + 1]) {
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }
    printf("\nThe given %d numbers in ascending order:\n", n);
    for (i = 0; i < n; i++)
        printf("%d \t", weight[i]);
    // Check if the sum is larger than the total of the input set
    if (total < sum)
        printf("\nSubset construction is not possible\n");
    else {
        // Initialize the inclusion array to all 0's
        for (i = 0; i < n; i++)
            inc[i] = 0;
        printf("\nThe solution using backtracking is:\n");
        // Call the sumset function to find the solution
        sumset(-1, 0, total);
    }
    return 0;
}
