#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int n = 4; 
int p[N] = {1, 2, 1, 1};
int d[N] = {1, 3, 2, 1};
int w[N] = {5, 10, 6, 3}; 
int s[N]; 
int f[N]; 
int upperbound = INT_MAX;
int best_time; 
int best_included[N];

int calcost(int job, int included[N]){
    included[job]=1;
    int cost = 0;
    
    for (int i = 0; i <= job; i++){
        if (included[i] == 0){
            cost += w[i];
        }
    }
    return cost;
}

int calupperbound(int included[N]){
    
    int cost = 0;
    
    for (int i = 0; i < N; i++){
        if (included[i] == 0){
            cost += w[i];
        }
    }
    
    return cost;
}

void solve(int job, int depth, int included[N], int cost)
{
    for (int i = job+1; i < N; i++){
        if (included[i] == 0){
            if (job == 0){
                s[i] = 0;
            } else {
                s[i] = f[job-1];
            }
            
            f[i] = s[i] + p[i];
            if (f[i] <= d[i] ){
               // printf("%d %d \n",calcost(i,included),upperbound);
                int cost1=calcost(i,included);
                if(cost1<upperbound){
                included[i]=1;
                upperbound=calupperbound(included);
                best_time = upperbound;
            for (int i = 0; i < N; i++){
                best_included[i] = included[i];
            }
                solve(i, depth+1, included, cost1);
                included[i] = 0;
                }
            }
            included[i] = 0;
        }
    }
}

int main()
{
    best_time =INT_MAX;
    int included[N] = {0};
    solve(0, 0, included, 0);

    printf("Minimum cost: %d\n", best_time);
    printf("Jobs included: ");
    for (int i = 0; i < N; i++) {
        if (best_included[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");

    printf("Path taken: ");
    int current_time = 0;
    for (int i = 0; i < N; i++) {
        if (best_included[i] == 1) {
            printf("%d ", i+1);
            current_time += p[i];
        }
    }
    printf("\n");

    return 0;
}
