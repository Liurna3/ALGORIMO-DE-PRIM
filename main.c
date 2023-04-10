
#include "./struct/linkedListNode.h"
#include "./struct/linkedList.h"
#include "./struct/priorityQueue.h"
#include "./struct/graph.h"
#include "./utils.h"

#include <stdlib.h>
#include <stdio.h>

void inputGraph(Graph *graph);

int main()
{
    Graph g;
    inputGraph(&g);

    // metodo de prim aquí

    graphFree(&g);
    return 0;
}

/**
 * Capturar un grafo
 */
void inputGraph(Graph *graph)
{
    int nodos;
    int peso;
    int op;

input_init:
    puts("Numero de nodos en el grafo?:");
    scanf("%d", &nodos);

    puts("Confirmar (1.si / 2.no):");
    scanf("%d", &op);

    if (op == 2)
    {
        goto input_init;
    }

    // inicializar grafo y capturar los pesos
    graphInit(graph, nodos);

    for (int i = 0; i < nodos; i++)
    {
        for (int j = i; j < nodos; j++)
        {
            if (graphValidPosition(graph, i, j))
            {
                // capturar el peso de cada vertice
                printf("Peso entre los nodos %d y %d?:\n", i, j);
                scanf("%d", &peso);
                graphSetEdgeWeight(graph, i, j, peso);
            }
        }
    }

    // mostrar la matriz de adyacencia
    puts("Grafo capturado:");
    displayAdjacencyMatrix(graph);

    puts("Los pesos son correctos (1.si / 2.no)?:");
    scanf("%d", &op);

    if (op != 1)
    {
        // si la captura fue incorrecta reinicia
        graphFree(graph);
        goto input_init;
    }
}