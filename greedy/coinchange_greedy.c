#include <stdio.h>
#define size 9
#define MAX 20
 
// All denominations of Indian Currency
int coins[size] = { 1, 2, 5, 10, 20,
                     50, 100, 200, 2000 };
 
void findMin(int cost)
{
    int coinList[MAX] = { 0 };
    int i, k = 0;
 
    for (i = size - 1; i >= 0; i--) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            // Add coin in the list
            coinList[k++] = coins[i];
        }
    }
 
    for (i = 0; i < k; i++) {
        // Print
        printf("%d ", coinList[i]);
    }
    return;
}
 
int main(void)
{
    // input value
    int n = 500;
 
    printf("Following is minimal number"
           "of change for %d: ",
           n);
    findMin(n);
    return 0;
}