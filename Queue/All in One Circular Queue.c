#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int frontIndex;
    int rearIndex;
    int *arr;
} Queue;

int IsFull(Queue *q)
{
    if ((q->rearIndex + 1) % q->size == q->frontIndex)
    {
        return 1;
    }
    return 0;
}

int IsEmpty(Queue *q)
{
    if (q->frontIndex == q->rearIndex)
    {
        return 1;
    }
    return 0;
}

void Enqueue(Queue *q, int data)
{
    if (IsFull(q))
    {
        printf("Queue is Full");
        return;
    }
    else
    {
        q->rearIndex = (q->rearIndex + 1) % q->size;
        q->arr[q->rearIndex] = data;
    }
}

int Dequeue(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        exit(1);
    }
    else
    {
        int data;
        q->frontIndex = (q->frontIndex + 1) % q->size;
        data = q->arr[q->frontIndex];
        return data;
    }
}

Queue *create(Queue *q, int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        Enqueue(q, data);
    }
    return q;
}

int peek(Queue *q, int index)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty.");
        return -1;
    }
    int i = 0;
    while (i != index)
    {
        q->frontIndex++;
        i++;
    }
    return q->arr[q->frontIndex];
}

void Display(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        return;
    }

    for (int i = q->frontIndex + 1; i <= q->rearIndex; i++)
    {
        printf("%d. %d\n", i + 1, q->arr[i]);
    }
}

void freeQueue(Queue **q)
{
    free((*q)->arr);
    free(*q);
    *q = NULL;
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = 10;
    q->frontIndex = -1;
    q->rearIndex = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int n;
    printf("Enter number of elements of the Queue: ");
    scanf("%d", &n);

    if (n <= 0 || n >= q->size)
    {
        printf("Enter a valid size of the Queue: ");
        exit(1);
    }

    q = create(q, n);

    int index, choice, data;
    while (1)
    {
        printf("\n");
        printf("1. Enqueue a data\n");
        printf("2. Dequeue a data\n");
        printf("3. Peek\n");
        printf("4. Print the Top Element\n");
        printf("5. Print the Bottom Element\n");
        printf("6. Print all the elements of the Queue\n");
        printf("7. Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to Enqueue: ");
            scanf("%d", &data);
            Enqueue(q, data);
            break;
        case 2:
            data = Dequeue(q);
            printf("The Deleted Element is %d \n", data);
            break;
        case 3:
            printf("Enter the index  for peeking: ");
            scanf("%d", &index);
            if (index <= 0 || index >= n)
            {
                printf("Enter a Valid Index.");
                break;
            }

            data = peek(q, index);
            printf("Element at Index %d is %d \n", index, data);
            break;
        case 4:
            printf("The element at the top is %d", q->arr[q->frontIndex + 1]);
            break;
        case 5:
            printf("The element at the bottom is %d", q->arr[q->rearIndex]);
            break;
        case 6:
            printf("The elements of the Queue:\n");
            Display(q);
            break;
        case 7:
            exit(1);
        default:
            printf("\nInvalid Choice! Please enter a valid number.\n");
            break;
        }
    }

    freeQueue(&q);

    return 0;
}
