#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->size - 1;
}

Stack *create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    printf("Enter size of the stack: ");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("Memory Allocation Failed.\n");
        free(s);
        return NULL;
    }
    return s;
}

void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow. Can't push %d\n", data);
        return;
    }

    s->top++;
    for (int i = s->top; i >= 0; i--)
    {
        s->arr[i + 1] = s->arr[i];
    }
    s->arr[0] = data;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow. Can't pop.\n");
        return -1;
    }

    int data = s->arr[0];
    for (int i = 0; i < s->top + 1; i++)
    {
        s->arr[i] = s->arr[i + 1];
    }
    s->top--;
    return data;
}

int peek(Stack *s, int index)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow, Can't peek\n");
        return -1;
    }

    if (index < 0 || index > s->top)
    {
        printf("Invalid Index.\n");
        return -1;
    }

    return s->arr[index];
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty Stack.\n");
        return;
    }

    for (int i = 0; i <= s->top; i++)
    {
        printf("Data %d: %d\n", i, s->arr[i]);
    }
    return;
}

void freeStack(Stack **s)
{
    free((*s)->arr);
    free(*s);
}

int main()
{
    Stack *s = create();
    if (s == NULL)
    {
        return 1;
    }

    int data, choice;
    while (1)
    {
        printf("\nChoice:\n1. Push\n2. Pop\n3. Peek\n4. The top Element of the Stack.\n5. The Bottom Element of the Stack.\n6. Display\n7. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you wanna push: ");
            scanf("%d", &data);

            push(s, data);
            break;
        case 2:
            data = pop(s);
            printf("The popped data: %d\n", data);
            break;
        case 3:
            printf("Enter the index whose data you wanna peek: ");
            scanf("%d", &data);

            int p = peek(s, data);
            if (p != -1)
            {
                printf("The data at index '%d' is %d", data, p);
            }
            break;
        case 4:
            if (!isEmpty(s))
            {
                printf("The top Element of the Stack is %d.\n", s->arr[0]);
            }
            else
            {
                printf("The Stack is Empty.\n");
            }

            break;
        case 5:
            if (!isEmpty(s))
            {
                printf("The Bottom Element of the Stack is %d.\n", s->arr[s->top]);
            }
            else
            {
                printf("The Stack is Empty.\n");
            }
            break;
        case 6:
            printf("The Stack:\n");
            display(s);
            break;
        case 7:
            printf("Exiting...\n");
            freeStack(&s);
            exit(0);
        default:
            printf("Enter a valid choice.");
            break;
        }
    }

    return 0;
}