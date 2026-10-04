#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} node_t;

// Function to create a new node
node_t* createNode(int key) {
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive insertion
node_t* insert(node_t* root, int key) {
    if(root == NULL) {
        return createNode(key);   // Empty spot → new node
    }
    if(key < root->key) {
        root->left = insert(root->left, key);   // Go left
    } else if(key > root->key) {
        root->right = insert(root->right, key); // Go right
    }
    return root;
}

// Find minimum value node (used in deletion)
node_t* findMin(node_t* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Recursive deletion
node_t* deleteNode(node_t* root, int key) {
    if(root == NULL) return root;

    if(key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        if(root->left == NULL) {
            node_t* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            node_t* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        node_t* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Inorder traversal (sorted order)
void inorder(node_t* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    node_t* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Delete nodes
    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
