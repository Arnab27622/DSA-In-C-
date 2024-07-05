#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the AVL tree
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to get the height of a node
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to create a new node with the given data
Node *newNode(int data)
{
    // Allocate memory for the new node
    Node *node = (Node *)malloc(sizeof(Node));
    // Check if memory allocation is successful
    if (node == NULL)
    {

        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Assign data to the new node and initialize other fields
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to perform a right rotation
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Function to insert a new key into the AVL tree
Node *insert(Node *node, int data)
{
    // If the tree is empty, create a new node
    if (node == NULL)
        return newNode(data);

    // Perform standard BST insertion
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
    {
        printf("Duplicate key found. Ignoring.\n");
        return node;
    }

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of the current node
    int balance = getBalance(node);

    // Perform rotations if necessary to balance the tree
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform in-order traversal of the AVL tree
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function
int main()
{
    Node *root = NULL;
    int data;
    char choice;

    // Insert nodes into the AVL tree
    do
    {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Print the in-order traversal of the AVL tree
    printf("InOrder Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}