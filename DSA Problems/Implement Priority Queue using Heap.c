#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int priority;
} PQNode;

typedef struct
{
    PQNode *heap;
    int capacity;
    int size;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (pq == NULL)
    {
        printf("Memory allocation failed for priority queue.\n");
        exit(EXIT_FAILURE);
    }
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (PQNode *)malloc(capacity * sizeof(PQNode));
    if (pq->heap == NULL)
    {
        printf("Memory allocation failed for heap.\n");
        free(pq);
        exit(EXIT_FAILURE);
    }
    return pq;
}

void swap(PQNode *a, PQNode *b)
{
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PQNode *heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index].priority < heap[parent].priority)
        {
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(PQNode *heap, int index, int size)
{
    int leftChild, rightChild, smallest;
    while (index < size)
    {
        smallest = index;
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        if (leftChild < size && heap[leftChild].priority < heap[smallest].priority)
        {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild].priority < heap[smallest].priority)
        {
            smallest = rightChild;
        }
        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

void enqueue(PriorityQueue *pq, int data, int priority)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }
    PQNode newNode = {data, priority};
    pq->heap[pq->size] = newNode;
    pq->size++;
    heapifyUp(pq->heap, pq->size - 1);
}

int dequeue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = pq->heap[0].data;
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq->heap, 0, pq->size);
    return data;
}

int isEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

void freePriorityQueue(PriorityQueue *pq)
{
    free(pq->heap);
    free(pq);
}

int main()
{
    PriorityQueue *pq = createPriorityQueue(10);

    enqueue(pq, 10, 3);
    enqueue(pq, 20, 2);
    enqueue(pq, 30, 1);
    enqueue(pq, 40, 5);
    enqueue(pq, 50, 4);

    while (!isEmpty(pq))
    {
        int data = dequeue(pq);
        printf("Dequeued element: %d\n", data);
    }

    freePriorityQueue(pq);

    return 0;
}