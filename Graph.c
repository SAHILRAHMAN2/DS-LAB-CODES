#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int adjMatrix[MAX][MAX];
    int numVertices;
} Graph;

void createGraph(Graph* g);
void bfs(Graph* g, int start);
void dfs(Graph* g, int start);
void dfsUtil(Graph* g, int vertex, bool visited[]);

int main() {
    Graph g;
    int choice, start;

    do {
        printf("\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. Print reachable nodes using BFS\n");
        printf("3. Print reachable nodes using DFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph(&g);
                break;
            case 2:
                printf("Enter starting node (0 to %d): ", g.numVertices - 1);
                scanf("%d", &start);
                bfs(&g, start);
                break;
            case 3:
                printf("Enter starting node (0 to %d): ", g.numVertices - 1);
                scanf("%d", &start);
                dfs(&g, start);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void createGraph(Graph* g) {
    int i, j, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &g->numVertices);
    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (from_vertex to_vertex):\n");
    for (i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        g->adjMatrix[from][to] = 1; 
    }
}

void bfs(Graph* g, int start) {
    bool visited[MAX] = {false};
    int queue[MAX], front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    printf("BFS from node %d: ", start);
    while (front < rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(Graph* g, int start) {
    bool visited[MAX] = {false};
    printf("DFS from node %d: ", start);
    dfsUtil(g, start, visited);
    printf("\n");
}

void dfsUtil(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

