#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

// Corrected function to create a new node
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function for in-order traversal
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->key);
        inorder(root->right);
    }
}

// Function to insert a new node with a given key
struct node *insert(struct node *node, int key) {
    if (node == NULL) {
        return newNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to find the minimum value node
struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function
int main() {
    struct node *root = NULL;
    int item, choice, cont;

    do {
        printf("1: Insertion\t 2: Deletion\t 3: Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Do you want to continue (1 for yes / 0 for no)? ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}
