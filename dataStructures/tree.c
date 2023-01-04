#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *pointer;
    pointer = (struct Node *)malloc(sizeof(struct Node));
    pointer->data = data;
    pointer->left = NULL;
    pointer->right = NULL;
    return pointer;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}

int main()
{
    //the tree:
    //                                           4
    //                     ______________________|________________________
    //                    |                                               |
    //        ____________3___________                      ______________7______________
    //       |                        |                    |                             |
    //   ____8_____             ______6______        ______3_______              ________7_______
    //  |          |           |             |      |              |            |                |
    //  2          7           9             6      1              5            4                3

    struct Node *root = createNode(4);
    struct Node *left = createNode(3);
    struct Node *right = createNode(7);
    struct Node *left_left = createNode(8);
    struct Node *left_right = createNode(6);
    struct Node *right_left = createNode(3);
    struct Node *right_right = createNode(7);
    struct Node *left_left_left = createNode(2);
    struct Node *left_left_right = createNode(7);
    struct Node *left_right_left = createNode(9);
    struct Node *left_right_right = createNode(6);
    struct Node *right_left_left = createNode(1);
    struct Node *right_left_right = createNode(5);
    struct Node *right_right_left = createNode(4);
    struct Node *right_right_right = createNode(3);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->left = right_left;
    right->right = right_right;
    left_left->left = left_left_left;
    left_left->right = left_left_right;
    left_right->left = left_right_left;
    left_right->right = left_right_right;
    right_left->left = right_left_left;
    right_left->right = right_left_right;
    right_right->left = right_right_left;
    right_right->right = right_right_right;

    while (1)
    {
        int operation;
        printf("Enter Operation...");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            printf("The preOrder traversal of the tree is...\n");
            preOrder(root);
        }
        break;
        case 2:
            printf("The inOrder traversal of the tree is...\n");
            inOrder(root);
            break;
        case 3:
            printf("The postOrder traversal of the tree is...\n");
            postOrder(root);
            break;
        }
    }
    return 0;
}