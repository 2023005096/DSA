#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

int searchBST(struct node* root, int value) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return searchBST(root->left, value);
    } else {
        return searchBST(root->right, value); 
    }
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
  }
}
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->data)	
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);

  return node;
}

int main() {
  struct node *root = NULL;
int Searchkey = 40;
  root = insert(root, 40);
  root = insert(root, 30);
  root = insert(root, 10);
  root = insert(root, 60);
  root = insert(root, 70);
  root = insert(root, 50);
  root = insert(root, 20);
  root = insert(root, 90);
  root = insert(root, 80);
  printf("Inorder traversal: ");
  inorder(root);


    if (searchBST(root, Searchkey)) {
        printf("Value %d found in the BST.\n", Searchkey);
    } else {
        printf("Value %d not found in the BST.\n", Searchkey);
    }
    
}
