#include <stdio.h>
#include <stdlib.h>
#include "./MatrizAdj.h"
#include"../queue/queue.h"

Graph initGraph(int vertices) {
    Graph G;
    G.vertices = vertices;
    G.Edge = 0;
    G.matrixAdj = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        G.matrixAdj[i] = (int *)calloc(vertices, sizeof(int));
    }
    return G;
}

void insertEdge(Graph *G, int v, int w) {
    G->matrixAdj[v][w] = 1;
    G->matrixAdj[w][v] = 1;
    G->Edge++;
}

void removeEdge(Graph *G, int v, int w) {
    G->matrixAdj[v][w] = 0;
    G->matrixAdj[w][v] = 0;
    G->Edge--;
}

int DFS(Graph *G, int vertices, int currentVertex, int *visited) {
    visited[currentVertex] = 1;
    printf("Visited %d\n", currentVertex);

    for (int i = 0; i < vertices; i++){
        if(G->matrixAdj[currentVertex][i] && !visited[i]){
            DFS(G, vertices, i, visited);
        }
    }
}

int BFS(Graph *G, int currentVertex){
    int *visited; Queue *q;

    initQueue(&q, G->vertices);

    visited[currentVertex] = 1;
    enqueue(&q, currentVertex);

    while(!isQueueEmpty(&q)){
        currentVertex = dequeue(&q);
        printf("Visistado %d \n", currentVertex);
        for (int i = 0; i < 0; i++){
            if (G->matrixAdj[currentVertex][i] && !visited[i]){
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    freeQueue(&q);
}

void printGraph(Graph G) {
    printf("Total of vertices: %d, total of arcs: %d\n", G.vertices, G.Edge);
    
    for (int i = 0; i < G.vertices; i++) {
        printf("Vertex %d, arcs: ", i);
        
        int printed = 0;
        for (int j = 0; j < G.vertices; j++) {
            if (G.matrixAdj[i][j] == 1) {
                if (printed) {
                    printf(", ");
                }
                printf("%d", j);
                printed = 1;
            }
        }
        printf("\n");
    }
}

void freeGraph(Graph G) {
    for (int i = 0; i < G.vertices; i++) {
        free(G.matrixAdj[i]);
    }
    free(G.matrixAdj);
}