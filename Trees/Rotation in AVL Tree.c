#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

Node *createKey(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed.");
        exit(1);
    }

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getHeight(Node *key)
{
    if (key == NULL)
    {
        return 0;
    }
    return key->height;
}

int getBalanceFactor(Node *key)
{
    if (key == NULL)
    {
        return 0;
    }
    return getHeight(key->left) - getHeight(key->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createKey(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    // left Right Case
    if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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
        printf("1. Insert a new key\n2. InOrder Traversal.\n3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data of new key: ");
            scanf("%d", &data);

            root = insert(root, data);
            break;
        case 2:
            printf("InOrder Traversal:\n");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Exiting...");
            exit(0);
        default:
            printf("Enter a valid choice.");
            break;
        }
    }

    return 0;
}
