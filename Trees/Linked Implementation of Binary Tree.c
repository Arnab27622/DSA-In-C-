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
        printf("Enter either 'l' or 'r'");
        return root;
    }

    return root;
}

void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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
void postOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *root = NULL;
    int data, choice;

    while (1)
    {
        printf("1. Insert a new node.\n2. Display PreOrder Traversal.\n3. Display InOrder Traversal.\n4. Display PostOrder Traversal.\n5. Exit.\n");
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
            printf("PreOrder Traversal:\n");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("InOrder Traversal:\n");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("PostOrder Traversal:\n");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...");
            printf("\n");
            exit(0);
            break;
        default:
            printf("Enter a valid choice");
        }
    }

    return 0;
}