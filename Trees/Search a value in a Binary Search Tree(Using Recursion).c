#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    printf("Enter 'l' to insert as left Node or 'r' to insert as right Node: ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'l')
    {
        root->left = insertNode(root->left, data);
    }
    else if (choice == 'r')
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        printf("Enter a valid choice.");
        return root;
    }
    return root;
}

Node *Search(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        return root;
    }
    else if (value < root->data)
    {
        return Search(root->left, value);
    }
    else
    {
        return Search(root->right, value);
    }
}

int main()
{
    Node *root = NULL;
    int data, choice;

    while (1)
    {
        printf("1. Insert a new node.\n2. Search a value.\n3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data of new node: ");
            scanf("%d", &data);

            root = insertNode(root, data);
            break;
        case 2:
            printf("Enter the data you want to search: ");
            scanf("%d", &data);

            Node *s = Search(root, data);
            if (s != NULL)
            {
                printf("Found %d.", s->data);
            }
            else
            {
                printf("%d not found.", s->data);
            }
            break;
        case 3:
            printf("Exiting...");
            exit(0);
        default:
            printf("Enter a valid Choice.");
            break;
        }
    }

    return 0;
}