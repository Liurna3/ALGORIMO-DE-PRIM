#include "./struct/linkedListNode.h"
#include "./struct/linkedList.h"
#include "./struct/priorityQueue.h"
#include "./struct/graph.h"
#include "./utils.h"

#include <stdlib.h>
#include <stdio.h>

void inputGraph(Graph *graph);
void displayPrim(Graph *graph);
int nodosCompletados(int *visited, int lenght);

int main()
{
    Graph g;
    int opc = 0;
    inputGraph(&g);

    do
    {
        puts("1. Capturar nuevo grafo");
        puts("2. Algoritmo de Prim");
        puts("3. Salir");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            graphFree(&g);
            inputGraph(&g);
            break;
        case 2:
            displayPrim(&g);
            break;
        case 3:
            break;
        default:
            puts("Opcion invalida");
            break;
        }
    } while (opc != 3);

    graphFree(&g);
    return 0;
}

/**
 * Capturar un grafo
 */
void inputGraph(Graph *graph)
{
    // numero de nodos 
    int nodos; 
    // peso entre dos nodos capturados
    int peso;
    // operacion, se usa para  confirmar las entradas
    int op;

input_init:
    puts("Numero de nodos en el grafo: ");
    scanf("%d", &nodos);

    puts("Confirmar 1. Si  2. No: ");
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
                printf("Inserte el peso entre los nodos %d y %d:\n", i, j);
                scanf("%d", &peso);
                graphSetEdgeWeight(graph, i, j, peso);
            }
        }
    }

    // mostrar la matriz de adyacencia
    puts("Grafo capturado :");
    displayAdjacencyMatrix(graph);
}

void displayPrim(Graph *graph)
{
    PriorityQueue queue;
    priorityQueueInit(&queue);

    int *visited = (int *)malloc(sizeof(int) * graphLenght(graph));
    int nodoActual = 0;
    // inicializar el arreglo de visitados en 0
    for (int i = 0; i < graphLenght(graph); i++)
    {
        visited[i] = 0;
    }

    printf("La lista de prim es: ");

    do
    {
        
        
        // agregar los nodos adyacentes a la cola de prioridad
        for(int j = 0; j < graphLenght(graph); j++)
        {
            if(graphValidPosition(graph, nodoActual, j))
            {
                priorityQueueEnqueue(&queue, linkedListNodeCreate(j, graphGetEdgeWeight(graph, nodoActual, j)));
            }
        }

        // marcar el nodo actual como visitado
        visited[nodoActual] = 1;
        printf(" %d ->", nodoActual);

        // obtener el nodo con menor prioridad mientras no este visitado
        while (visited[nodoActual] == 1 && !nodosCompletados(visited, graphLenght(graph)))
        {
            nodoActual = priorityQueueDequeue(&queue)->node;
        }

    } while (!nodosCompletados(visited, graphLenght(graph)));
    printf("x\n");
    
}

int nodosCompletados(int *visited, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (visited[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

