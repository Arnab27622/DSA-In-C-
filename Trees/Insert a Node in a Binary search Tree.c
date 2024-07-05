#include <stdio.h>
#include <stdlib.h>

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

    printf("Enter 'l' to insert as left child or 'r' to insert as right child: ");
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

Node *Insert(Node *root, int data)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (data == root->data)
        {
            return root;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    Node *new = createNode(data);
    if (data < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int data, choice;

    while (1)
    {
        printf("1. Insert a new node.\n2. Insert a value.\n3. InOrder Traversal.\n4. Exit.\n");
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
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);

            Node *s = Insert(root, data);
            break;
        case 3:
            printf("InOrder Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...");
            exit(0);
        default:
            printf("Enter a valid Choice.");
            break;
        }
    }

    return 0;
}
