#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

int isEmpty(Queue *ptr)
{
    return front == NULL;
}

int isFull(Queue *ptr)
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Memory allocation failed, queue is full
    }
    return 0; // Memory allocation successful, queue is not full
}
void Enqueue(int data)
{
    Queue *ptr = (Queue *)malloc(sizeof(Queue));
    if (ptr == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

int Dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty.");
        return -1;
    }
    else
    {
        Queue *ptr = front;
        int data;
        front = front->next;
        data = ptr->data;
        free(ptr);
        return data;
    }
}

void Create(int size)
{
    int data;
    for (int i = 0; i < size; i++)
    {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        Enqueue(data);
    }
}

int peek(int index)
{
    if (isEmpty(front))
    {
        printf("Queue is Empty.");
        return -1;
    }
    else
    {
        Queue *ptr = front;
        for (int i = 0; i <= index; i++)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
}

void Display()
{
    int i = 0;
    Queue *current = front;
    while (current != NULL)
    {
        printf("%d. %d\n", i + 1, current->data);
        current = current->next;
        i++;
    }
}

void freeQueue(Queue **head)
{
    if (*head == NULL)
        return;

    Queue *current = *head;
    Queue *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main()
{
    int n;
    printf("Enter number of data in the queue: ");
    scanf("%d", &n);

    Create(n);

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
            Enqueue(data);
            break;
        case 2:
            data = Dequeue();
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

            if (data != -1)
                data = peek(index);
            printf("Element at Index %d is %d \n", index, data);
            break;
        case 4:
            printf("The element at the top is %d", front->data);
            break;
        case 5:
            printf("The element at the bottom is %d", rear->data);
            break;
        case 6:
            printf("The elements of the Queue:\n");
            Display();
            break;
        case 7:
            printf("Exiting...\n");
            freeQueue(&front);
            exit(0);
        default:
            printf("\nInvalid Choice! Please enter a valid number.\n");
            break;
        }
    }

    return 0;
}