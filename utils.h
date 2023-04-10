
/**
 *
 */
void pqEnqueue(PriorityQueue *pq, PRIORITY_DATA_TYPE priority)
{
    priorityQueueEnqueue(pq, linkedListNodeCreate(priority));
}

/**
 *
 */
LinkedListNode *pqPeek(PriorityQueue *pq)
{
    return priorityQueuePeek(pq);
}

/**
 *
 */
LinkedListNode *pqGet(PriorityQueue *pq, int position)
{
    return priorityQueueGet(pq, position);
}

/**
 *
 */
PRIORITY_DATA_TYPE pqDequeue(PriorityQueue *pq)
{
    LinkedListNode *a = priorityQueueDequeue(pq);
    PRIORITY_DATA_TYPE priority = a->priority;
    free(a);

    return priority;
}

void displayAdjacencyMatrix(Graph *graph)
{
    int lenght = graphLenght(graph);

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            if (!graphValidPosition(graph, i, j))
            {
                printf(" - ");
                continue;
            }

            printf("%2d ", graphGetEdgeWeight(graph, i, j));
        }

        printf("\n");
    }
}