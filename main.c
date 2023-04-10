
#include "./struct/linkedListNode.h"
#include "./struct/linkedList.h"
#include "./struct/priorityQueue.h"
#include "./struct/graph.h"
#include "./utils.h"

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

    capturar_nodos:
    puts("Numero de nodos en el grafo?:");
    scanf("%d", &nodos);

    if (nodos < 2)
    {
        puts("El minimo de nodos es 2!!");
        goto capturar_nodos;
    }

    graphInit(graph, nodos);

    for (int i = 0; i < nodos; i++)
    {
        for (int j = i; j < nodos; j++)
        {
            // capturar el peso de cada vertice 
            if (!graphValidPosition(graph, i, j))
                continue;
            
            printf("Peso entre los nodos %d y %d?:\n", i,j);
            scanf("%d", &peso);
            graphSetEdgeWeight(graph,i,j,peso);
        }
    }

    puts("Grafo capturado:");
    displayAdjacencyMatrix(graph);

    puts("Los pesos son correctos (1.si / 2.no)?:");
    scanf("%d", &op);

    if (op != 1)
    {
        graphFree(graph);
        goto capturar_nodos;
    }
}