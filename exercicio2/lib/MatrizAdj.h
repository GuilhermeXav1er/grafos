#ifndef MatrizAdj_H
#define MatrizAdj_H

typedef struct {
    int vertices;
    int Edge;
    int **matrixAdj;
} Graph;

Graph initGraph(int vertices);
void insertEdge(Graph *G, int v, int w);
void removeEdge(Graph *G, int v, int w);
void printGraph(Graph G);
void freeGraph(Graph G);

#endif