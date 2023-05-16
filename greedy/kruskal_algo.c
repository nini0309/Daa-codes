#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n,cost[9][9], ne = 1;
int min, mincost = 0,  parent[9];

int find(int i)//finding parent
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)//union function
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void main()
{
    
    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);//parent of u
        v = find(v);//parent of v
        
        if (uni(u, v)!=0)
        {
            printf("%dedge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);

}

// #include<stdio.h>
// #include<limits.h>
// #include<stdbool.h>

// #define V 6

// void printMST(int parent[], int graph[V][V]) {
//     printf("Edge   Weight\n");
//     for (int i = 1; i < V; i++) {
//         printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
//     }
// }

// int find(int parent[], int i) {
//     // Find operation to determine the subset in which the element belongs
//     while (parent[i] != i) {
//         i = parent[i];
//     }
//     return i;
// }

// void unionSets(int parent[], int rank[], int x, int y) {
//     // Union operation to merge two subsets
//     int xRoot = find(parent, x);
//     int yRoot = find(parent, y);

//     if (rank[xRoot] < rank[yRoot]) {
//         parent[xRoot] = yRoot;
//     } else if (rank[xRoot] > rank[yRoot]) {
//         parent[yRoot] = xRoot;
//     } else {
//         parent[yRoot] = xRoot;
//         rank[xRoot]++;
//     }
// }

// void kruskalMST(int graph[V][V]) {
//     int parent[V];
//     int rank[V];
//     for (int i = 0; i < V; i++) {
//         parent[i] = i;
//         rank[i] = 0;
//     }

//     int edgeCount = 0;
//     int minWeight = INT_MAX;
//     int minSrc, minDest;

//     while (edgeCount < V - 1) {
//         // Find the minimum weight edge that does not create a cycle
//         for (int i = 0; i < V; i++) {
//             for (int j = 0; j < V; j++) {
//                 if (graph[i][j] && find(parent, i) != find(parent, j) && graph[i][j] < minWeight) {
//                     minWeight = graph[i][j];
//                     minSrc = i;
//                     minDest = j;
//                 }
//             }
//         }

//         // Perform union operation and print the selected edge
//         unionSets(parent, rank, minSrc, minDest);
//         printf("Edge %d: %d - %d    Weight: %d\n", edgeCount + 1, minSrc, minDest, minWeight);
//         edgeCount++;
//         minWeight = INT_MAX;
//     }
// }

// int main() {
//     int graph[V][V] = {
//         {0, 4, 6, 0, 0, 0},
//         {4, 0, 6, 3, 4, 0},
//         {6, 6, 0, 1, 8, 0},
//         {0, 3, 1, 0, 2, 3},
//         {0, 4, 8, 2, 0, 7},
//         {0, 0, 0, 3, 7, 0}
//     };

//     kruskalMST(graph);

//     return 0;
// }

