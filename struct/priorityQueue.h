/**
 * AUTOR: Luis Eduardo Galindo Amaya                           FECHA: 08-04-2023
 *
 * DESCRIPCIÓN:
 * Este archivo implementa los metodos para utilizar una lista enlazada como una 
 * cola con prioridad.
 */

#ifndef priorityQueue
#define priorityQueue

#include "linkedList.h"
#include <stdio.h>

typedef struct PriorityQueue
{
  LinkedList data;
} PriorityQueue;

/**
 * Inicializar la cola con prioridad
 * @param queue direccion a la lista
 */
void priorityQueueInit(PriorityQueue *queue)
{
  linkedListInit(&(queue->data));
}

/**
 * Numero de elementos en la lista
 * @param queue direccion a la lista
 */
int priorityQueueLenght(PriorityQueue *queue)
{
  return linkedListLenght(&(queue->data));
}

/**
 * Retorar si la lista esta vacia
 * @param queue direccion a la lista
 */
int priorityQueueEmpty(PriorityQueue *queue)
{
  return linkedListEmpty(&(queue->data));
}

/**
 * libera la memoria
 * @param queue direccion a la lista
 */
void priorityQueueFree(PriorityQueue *queue)
{
  linkedListFree(&(queue->data));
}

/**
 * Obtener la direccion en una posicion de la lista
 * @note esta funcion es para operaciones internas y debugging
 * @param queue direccion a la lista
 * @param position
 */
LinkedListNode *priorityQueueGet(PriorityQueue *queue, int position)
{
  return linkedListGet(&(queue->data), position);
}

/**
 * Revisar el primer valor de la lista
 * @param queue direccion a la lista
 * @return una copia del primer nodo
 */
LinkedListNode *priorityQueuePeek(PriorityQueue *queue)
{
  return priorityQueueGet(queue, 0);
}

/**
 * Eliminar el valor al inicio de la lista
 * @warning liberar la memoria a la direccion despues de usarla
 * @param queue direccion a la lista
 * @return direccion al elemnto eliminado
 */
LinkedListNode *priorityQueueDequeue(PriorityQueue *queue)
{
  LinkedListNode *foo = linkedListNodeCopy(priorityQueueGet(queue, 0));
  linkedListRemove(&(queue->data), 0);
  return foo;
}

/**
 * Insertar el nodo en la lista
 * @param queue direccion a la lista
 * @param node direccion al nodo
 */
void priorityQueueEnqueue(PriorityQueue *queue, LinkedListNode *node)
{
  int i = 0;

  while (i < priorityQueueLenght(queue))
  {
    // incrementar i hasta encontrar la posicion con
    // mayor prioridad que el nodo que queremos insertar

    LinkedListNode *current = priorityQueueGet(queue, i);

    if (current->priority > node->priority)
      // lista en orden asendente
      break;

    i++;
  }

  // insertar el nodo en 'i'
  linkedListInsert(&(queue->data), node, i);
}

#endif