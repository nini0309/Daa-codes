#include <stdio.h>

void main()
{
    int graph[][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};

    int i, j, n = 5, cost[30][30], start = 0, visited[10], distance[10], pred[10], min, nextnode;
    int dest = 4; // define the destination node

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                cost[i][j] = 999; //infinty
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        visited[i] = 0;
        pred[i] = start;
    }

    distance[start] = 0;
    visited[start] = 1;
    int count = 1;

    while (count < n && !visited[dest]) // stop once destination node is visited
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < min && visited[i] == 0)
            {
                min = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (min + cost[nextnode][i] < distance[i])
                {
                    distance[i] = min + cost[nextnode][i];
                    pred[i] = nextnode; // store the predecessor or parent node
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("Distance from %d to %d: %d\n",start, i, distance[i]);
        }
    }
    // display the shortest path to the destination node
    printf("Shortest path from %d to destination:\n",start);
    int path[n],current=dest;
    i=0;
    while(current!=-1 && current!=start)
    {
        path[i]=current;
        current=pred[current];
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(path[i]!=0){
        printf("%d<-",path[i]);

        }
    }
    printf("%d",start);
    printf("\n");
    printf("Minimum cost from %d to %d: %d\n", start, dest, distance[dest]);
}
