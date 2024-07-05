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
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
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

    char choice;
    printf("Enter 'l' to insert as left child or 'r' to insert as right child: ");
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
        printf("Invalid choice\n");
    }
    return root;
}

Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Node not found\n");
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    Node *root = NULL;

    int data, choice;
    while (1)
    {
        printf("\n1. Insert a new node\n2. Delete a node\n3. PreOrder Traversal\n4. InOrder Traversal\n5. PostOrder Traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data of the new node: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Enter the data you want to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("PreOrder Traversal: ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("InOrder Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("PostOrder Traversal: ");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }

    return 0;
}