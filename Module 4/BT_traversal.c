#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to create the binary tree recursively
struct Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;  // No node created
    }
    struct Node* newNode = createNode(data);  // Create a new node with the entered data

    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();  // Recursively create the left subtree

    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();  // Recursively create the right subtree

    return newNode;
}
// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
// Postorder traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create the binary tree
    printf("Create the binary tree:\n");
    struct Node* root = createTree();

    // Perform tree traversals
    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
