
/**
 * AUTOR: Luis Eduardo Galindo Amaya                           FECHA: 26-02-2023
 *
 * DESCRIPCIÓN:
 * En este archivo se almacenan todos los métodos para controlar una lista
 * enlazada.
 */

#ifndef linkedList
#define linkedList

#include "linkedListNode.h"
#include <stdlib.h>

typedef struct LinkedList
{
  struct LinkedListNode *nodes;
  int size;
} LinkedList;

/**
 * Longitud de la lista enlazada
 * @param lista direccion a la lista
 * @return int
 */
int linkedListLenght(LinkedList *list)
{
  return list->size;
}

/**
 * Devuelve verdadero si la lista esta vacía
 * @param list direccion a una lista
 * @return boolean
 */
short linkedListEmpty(LinkedList *list)
{
  return list->nodes == NULL;
}

/**
 * Devuelve verdadero si la posición NO es negativa y
 * existe dentro el arreglo
 * @param
 * @return
 */
short linkedListInvalidPosition(LinkedList *list, int position)
{
  /* tamaño es inferior a la posicion (hay menos elementos que la
     posicion solicitada), la posicion es un valor negativo */

  return position > linkedListLenght(list) || position < 0;
}

/**
 * Inicializar el arreglo
 * @param list dirección a una lista
 */
void linkedListInit(LinkedList *list)
{
  list->nodes = NULL;
  list->size = 0;
}

/**
 * Liberar un nodo de la lista que ya no se va a usar
 * @param node direccion del nodo
 */
void freeLinkedListNode(LinkedListNode *node)
{
  if (node == NULL)
  {
    printf("freeLinkedListNode: El nodo esta vacio\n");
    exit(EXIT_FAILURE);
  }

  free(node);
}

/**
 * Obtener un nodo de la lista
 * @param position
 * @return LinkedListNode
 */
LinkedListNode *linkedListGet(LinkedList *list, int position)
{
  LinkedListNode *current = list->nodes; /* primer elemento */

  if (linkedListInvalidPosition(list, position))
  {
    /* Si la posición solicitada es mas grande que la cantidad
       de nodo disponibles entonces termina */
    printf("linkedListGet: Posición fuera de rango!!\n");
    exit(EXIT_FAILURE);
  }

  if (linkedListEmpty(list))
  {
    /* No se puede extraer valores de una lista vacía */
    printf("linkedListGet: La lista esta vacia!!\n");
    exit(EXIT_FAILURE);
  }

  if (position == 0)
  {
    /* Primer elemento de la lista */
    return list->nodes;
  }

  for (int i = 0; i < position; i++)
  {
    /* caso generico */
    current = current->next;
  }

  return current;
}

/**
 * Insertar elementos en la lista
 * @param list dirección a una lista
 * @param node dirección a un nodo
 * @param position posición donde insertar el elemento
 */
void linkedListInsert(LinkedList *list, LinkedListNode *node, int position)
{
  LinkedListNode *new = node;
  LinkedListNode *current = list->nodes; /* primer elemento */
  LinkedListNode *previous = NULL;

  if (linkedListEmpty(list))
  {
    /* si no hay elementos en la lista inserta en la primera posición */
    list->nodes = node;
    list->size++;
    return;
  }

  if (linkedListInvalidPosition(list, position))
  {
    /* Si la posición solicitada es mas grande que la cantidad
       de nodo disponibles o la posicion es negativa entonces termina */
    printf("linkedListInsert: Posición %d fuera de rango!!\n", position);
    exit(EXIT_FAILURE);
  }

  if (position == 0)
  {
    /* insertar al inicio de la lista */
    new->next = current;
    list->nodes = new;
    list->size++;
    return;
  }

  for (int i = 0; i < position; i++)
  {
    /* caso generico */
    previous = current;
    current = current->next;
  }

  previous->next = new;
  new->next = current;
  list->size++;
}

/**
 * Eliminar elemento en una posicion
 * @param list direccion a la lista
 * @param position posición del elemeto
 */
void linkedListRemove(LinkedList *list, int position)
{
  LinkedListNode *current = list->nodes; /* primer elemento */
  LinkedListNode *previous = NULL;

  if (linkedListEmpty(list))
  {
    /* No se puede extraer valores de una lista vacía */
    printf("linkedListRemove: La lista esta vacia!!\n");
    exit(EXIT_FAILURE);
  }

  if (linkedListInvalidPosition(list, position))
  {
    /* no valores fuera de rango o negativos */
    printf("linkedListRemove: Posición fuera de rango!!\n");
    exit(EXIT_FAILURE);
  }

  if (position == linkedListLenght(list))
  {
    printf("linkedListRemove: Posición fuera de rango!!\n");
    exit(EXIT_FAILURE);
  }

  if (linkedListLenght(list) == 1)
  {
    /* si solo hay un elemento en lista */
    free(list->nodes);
    list->nodes = NULL;
    list->size = 0;
    return;
  }

  if (position == 0)
  {
    /* si se quiere eliminar el primer elemento */
    list->nodes = current->next;
    free(current);
    list->size--;
    return;
  }

  for (int i = 0; i < position; i++)
  {
    /* caso generico */
    previous = current;
    current = current->next;
  }

  previous->next = current->next;
  free(current);
  list->size--;
}

/**
 * eliminar el ultimo elemento de la lista
 * @param list direccion a la lista
 */
void linkedListRemoveLast(LinkedList *list)
{
  linkedListRemove(list, linkedListLenght(list) - 1);
}

/**
 * inserta un elemento al final de la lista
 * @param list direccio de la lista
 * @param node direccion del nuevo nodo
 */
void linkedListInsertLast(LinkedList *list, LinkedListNode *node)
{
  linkedListInsert(list, node, linkedListLenght(list));
}

/**
 * Liberar memoria del la lista enlazada
 * @param list direccion de la lista
 */
void linkedListFree(LinkedList *list)
{
  for (int i = linkedListLenght(list); i > 0; i--)
  {
    linkedListRemove(list, 0);
  }
}

#endif
