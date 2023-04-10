
/**
 * AUTOR: Luis Eduardo Galindo Amaya                           FECHA: 26-02-2023
 *
 * DESCRIPCIÓN:
 * En este archivo se encuentrara todos los metodos para crear nodos para
 * linkedList.
 */

#ifndef linkedListNode
#define linkedListNode

#define PRIORITY_DATA_TYPE int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNode
{
  /* Propiedades */
  int node;
  PRIORITY_DATA_TYPE priority;

  /* Required */
  struct LinkedListNode *next;
} LinkedListNode;

/**
 * Crear un nodo para la lista
 */
LinkedListNode *linkedListNodeCreate(int node, PRIORITY_DATA_TYPE priority)
{
  LinkedListNode *foo = malloc(sizeof(LinkedListNode));

  if (foo == NULL)
  {
    printf("LinkedListNodeCreate: No se pudo reservar memoria!!\n");
    exit(EXIT_FAILURE);
  }

  foo->node = node;
  foo->priority = priority;

  return foo;
}

/**
 * Imprime el valor en el stdio
 */
void linkedListNodeDisplay(LinkedListNode *node)
{
  printf("nodo %d, peso: %d\n",node->node, node->priority);
}

/**
 * Copiar un nodo de la lista
 * @param node direccion al nodo
 * @return
 */
LinkedListNode *linkedListNodeCopy(LinkedListNode *node)
{
  return linkedListNodeCreate(node->node,node->priority);
}

#endif
