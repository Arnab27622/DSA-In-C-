/* Imagine you are designing a system that manages a playlist of songs using a circular doubly linked list.
   How would you implement features such as adding a new song, deleting a song, shuffling the playlist, and playing songs in a loop efficiently?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node
{
    char data[MAX_SIZE];
    struct Node *prev;
    struct Node *next;
} Node;

Node *addToEmpty(Node *tail, char data[])
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    strcpy(ptr->data, data);

    ptr->next = ptr;
    ptr->prev = ptr;

    return ptr;
}

Node *addToTail(Node *tail, char data[])
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    strcpy(ptr->data, data);

    ptr->next = tail->next;
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;

    return tail;
}

Node *Create(Node *tail, char data[])
{
    if (tail == NULL)
    {
        tail = addToEmpty(tail, data);
    }
    else
    {
        tail = addToTail(tail, data);
    }

    return tail;
}

Node *DeleteAtFirst(Node *tail)
{
    Node *ptr = tail->next;

    tail->next = ptr->next;
    ptr->next->prev = tail;
    free(ptr);

    return tail;
}

Node *Delete(Node *tail, int index)
{
    if (index == 1)
    {
        tail = DeleteAtFirst(tail);
        return tail;
    }

    Node *ptr = tail->next;
    Node *p = ptr->next;
    int i = 1; // Start from index 1

    while (i != (index - 1))
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next->prev = ptr;

    if (p == tail)
    {
        tail = ptr;
    }

    free(p);

    return tail;
}

void shufflePlaylist(Node *tail)
{
    if (tail == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    Node *current = tail;
    Node *temp;
    int count = 0;

    // Count the number of nodes in the list
    do
    {
        count++;
        current = current->next;
    } while (current != tail);

    // Shuffle the playlist by swapping random pairs of nodes
    srand(time(NULL));
    for (int i = 0; i < count * 2; i++)
    {
        int pos1 = rand() % count;
        int pos2 = rand() % count;

        // Swap nodes at pos1 and pos2
        current = tail;
        for (int j = 0; j < pos1; j++)
        {
            current = current->next;
        }
        Node *node1 = current;

        current = tail;
        for (int j = 0; j < pos2; j++)
        {
            current = current->next;
        }
        Node *node2 = current;

        // Swap data
        char tempData[MAX_SIZE];
        strcpy(tempData, node1->data);
        strcpy(node1->data, node2->data);
        strcpy(node2->data, tempData);
    }

    printf("The PlatList has been Shuffled\n");
}

void playInLoop(Node *tail)
{
    if (tail == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    Node *current = tail->next;
    do
    {
        printf("Currently Playing: %s\n", current->data);
        // sleep(1);
        current = current->next;
    } while (current != tail->next);

    printf("The playList is now playing in loop\n");
}

void Display(Node *tail)
{
    if (tail == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    Node *ptr = tail->next;
    int i = 0;
    do
    {
        printf("Song %d: %s\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != tail->next);
}

void freeList(Node **tail)
{
    Node *current = (*tail)->next;
    Node *prev;

    while (current != *tail)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    free(current);

    *tail = NULL;
}

int main()
{
    Node *tail = NULL;

    char data[MAX_SIZE];
    int pos;

    while (1)
    {
        int choice;
        printf("\n");
        printf("1. Insert a New Song\n");
        printf("2. Delete a Song\n");
        printf("3. Shuffle The Playlist\n");
        printf("4. Play the List in loop\n");
        printf("5. Display the Whole Play List\n");
        printf("6. Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Name of the Song you want to Add: ");
            getchar(); // Consume newline character left in the input buffer
            fgets(data, MAX_SIZE, stdin);

            // Remove newline character if present
            data[strcspn(data, "\n")] = '\0';

            tail = Create(tail, data);
            break;
        case 2:
            printf("Enter the pos of the Song you want to Delete: ");
            scanf("%d", &pos);

            tail = Delete(tail, pos);
            break;
        case 3:
            printf("Do You Want to Shuffle Playlist, Then Press 'y' For yes and 'n' for no\n");
            char c;
            scanf(" %c", &c);
            if (c == 'y')
            {
                shufflePlaylist(tail);
            }
            break;
        case 4:
            printf("Do You Want to Play the Playlist in a loop, Then Press 'y' For yes and 'n' for no\n");
            char loop;
            scanf(" %c", &loop);
            if (loop == 'y')
            {
                playInLoop(tail);
            }
            break;
        case 5:
            printf("Your Play List of Songs:\n");
            Display(tail);
            break;
        case 6:
            printf("The Program Ends Here.\n");
            freeList(&tail);
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("\nInvalid Choice! Please enter a valid number.\n");
            break;
        }
    }

    return 0;
}