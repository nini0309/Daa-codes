#include<stdio.h>
#include<stdbool.h>
#define V 6


int minKey(int key[],bool mstSet[]){
    int min=999,min_index;
    for(int v=0;v<V;v++){
        if(mstSet[v]==false && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index;
}

void displayPath(int parent[],int source,int dest){
    int path[v],current=dest,i=0;
    while(current!=-1 && current!=source)
    {
        path[i]=current;
        current=parent[current];
        i++;
    }
    for(int i=0;i<v-1;i++){
        printf("%d<-",path[i]);
    }
    printf("%d",source);
}

// void displayPath(int source, int dest, int parent[]) {
//     int path[V];
//     int pathLen = 0;
//     int current = dest;
//     // The function then enters a while loop that continues until current is either the source vertex or -1. At each iteration, it adds the current vertex to the path array and increments the pathLen variable. It then updates the value of current to be the parent of the current vertex. This process continues until current is either the source vertex or -1.
//     while (current != -1 && current != source) {
//         path[pathLen] = current;
//         pathLen++;
//         current = parent[current];
//     }
//     //For including source vertex
//     path[pathLen] = source;
//     pathLen++;

//     if (current == -1) {
//         printf("There is no path from %d to %d in the Minimum Spanning Tree.\n", source, dest);
//     } else {
//         printf("The path from %d to %d in the Minimum Spanning Tree is: ", source, dest);
//         for (int i = pathLen - 1; i >= 0; i--) {
//             printf("%d", path[i]);
//             if (i > 0) {
//                 printf(" -> ");
//             }
//         }
//         printf("\n");
//     }
// }


void primMST(int graph[V][V]){
    int parent[V],key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=999;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V;count++){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && mstSet[v]==false && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for(int i=1;i<V;i++){
        printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
    }

    int source = 0; // Change this to the desired source vertex
    int dest = 3;   // Change this to the desired destination vertex
    displayPath(source, dest, parent);
}


void main(){
    int graph[V][V]={
        {0,2,0,0,0,4},
        {2,0,8,0,0,3},
        {0,8,0,6,1,0},
        {0,0,6,0,12,0},
        {0,0,1,0,12,2},
        {4,3,0,0,2,0},
      //{0,1,2,3,4,5}
    };

    primMST(graph);

    
}



// #include<stdio.h>
// #include<stdbool.h>
// #define v 6

// int minKey(int key[],bool mstset[]){
//     int minindex,min=999;
//     for(int i=0;i<v;i++){
//         if(mstset[i]==false && min>key[i]){
//             min=key[i];
//             minindex=i;
//         }
//     }
//     return minindex;
// }

// void displayPath(int parent[],int source,int dest){
//     int path[v],current=dest,i=0;
//     while(current!=-1 && current!=source)
//     {
//         path[i]=current;
//         current=parent[current];
//         i++;
//     }
//     for(int i=0;i<v-1;i++){
//         printf("%d<-",path[i]);
//     }
//     printf("%d",source);
// }

// void primMST(int graph[v][v]){
//     int key[v], parent[v];
//     bool mstset[v];
//     for(int i=0;i<v;i++){
//         mstset[i]=false;
//         key[i]=999;
//     }
//     key[0]=0;
//     parent[0]=-1;
//     for(int i=0;i<v;i++){
//         int u=minKey(key,mstset);
//         mstset[u]=true;
//         for(int j=0;j<v;j++){
//             if(graph[u][j]!=0 && key[j]>graph[u][j] && mstset[j]==false){
//                 key[j]=graph[u][j];
//                 parent[j]=u;
//             }
//         }
//     }

//     for(int i=1;i<v;i++){
//         printf("%d-%d=>%d\n",parent[i],i,graph[i][parent[i]]);
//     }
//     int source=0;
//     int dest=3;
//     displayPath(parent,source,dest);
// }

// void main(){
//     int graph[v][v]={
//         {0,2,0,0,0,4},
//         {2,0,8,0,0,3},
//         {0,8,0,6,1,0},
//         {0,0,6,0,12,0},
//         {0,0,1,0,12,2},
//         {4,3,0,0,2,0},
//       //{0,1,2,3,4,5}
//     };

//     primMST(graph);

    
// }
