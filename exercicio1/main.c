#include <stdio.h>
#include <stdlib.h>
#include "./lib/MatrizAdj.h"

int main(int argc, char *argv[]) {
    int n, i, x, y;
    Graph G;
    scanf("%d\n", &n);
    G = initGraph(n);
    while (scanf("%d %d\n", &x, &y) != EOF) {
        insertEdge(&G, x, y);
    }
    printGraph(G);

    return 0;
}