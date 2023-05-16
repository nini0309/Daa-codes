#include <stdio.h>

#define MAX_VERTICES 20

int numVertices;
int numColors;
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int vertexColors[MAX_VERTICES];

// Function to check if it's safe to color a vertex with a given color
int isSafe(int vertex, int color)
{
    for (int i = 0; i < numVertices; i++)
    {
        // check if there is an adjacent vertex with the same color
        if (adjacencyMatrix[vertex][i] && vertexColors[i] == color)
            return 0;
    }
    return 1;
}

// Function to assign colors to vertices using backtracking
int graphColoring(int vertex)
{
    // Base case: All vertices are colored
    if (vertex == numVertices)
        return 1;
    // Assign colors to the remaining vertices
    for (int color = 1; color <= numColors; color++)
    {
        // Check if it's safe to color the vertex with the given color
        if (isSafe(vertex, color))
        {
            vertexColors[vertex] = color;

            // Recursive call to color the next vertex
            if (graphColoring(vertex + 1))
                return 1;

            // Backtrack if a solution is not found with the current color
            vertexColors[vertex] = 0;
        }
    }

    return 0;
}

int main()
{
    // Read the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    // Read the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Read the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    // Try to color the graph using the given number of colors
    if (graphColoring(0))
    {
        // If a solution is found, print the minimum number of colors required
        printf("Graph can be colored using at most %d colors.\n", numColors);
        printf("Vertex colors:\n");
        for (int i = 0; i < numVertices; i++)
        {
            printf("Vertex %d: Color %d\n", i + 1, vertexColors[i]);
        }
    }
    else
    {
        // If a solution is not found, print a message indicating that
        printf("Graph cannot be colored using at most %d colors.\n", numColors);
    }

    return 0;
}