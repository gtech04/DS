#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* new_node, *root = NULL, *temp; // Correct initialization of root

void insertion(struct node* root, struct node* new_node)
{
    char ch;
    printf("Left child(l) or Right child(r): ");
    getchar(); // To consume the leftover newline character from previous input
    scanf("%c", &ch);
    switch(ch)
    {
        case 'l':
            if (root->left == NULL)
            {
                root->left = new_node;
            }
            else
            {
                insertion(root->left, new_node);
            }
            break;
        case 'r':
            if (root->right == NULL)
            {
                root->right = new_node;
            }
            else
            {
                insertion(root->right, new_node);
            }
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

void createNode()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    printf("Enter the Data: ");
    scanf("%d", &new_node->data);
    
    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        insertion(root, new_node);
    }
}

void inorder(struct node* temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node* temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node* temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

int main()
{
    int n, cond = 0;
    printf("BINARY TREE TRAVERSAL\n");
    printf("1. Create & Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");

    while (cond == 0)
    {
        printf("Enter Choice: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                createNode();
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                cond = 1;
                printf("Thank You\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
