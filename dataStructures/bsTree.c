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

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

struct Node *searchByRecursion(struct Node *root, int element)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (element == root->data)
    {
        return root;
    }
    else if (element < root->data)
    {
        return searchByRecursion(root->left, element);
    }
    else
    {
        return searchByRecursion(root->right, element);
    }
}

struct Node *searchByIteration(struct Node *root, int element)
{
    while (root != NULL)
    {
        if (element == root->data)
        {
            return root;
        }
        else if (element < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insertElement(struct Node *root, int element)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (element == root->data)
        {
            printf("Element already present in binary search tree\n");
            return;
        }
        else if (element < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *new = createNode(element);
    if (element < prev->data)
    {
        prev->left = new;
        printf("Element inserted in the binary search tree\n");
    }
    else
    {
        prev->right = new;
        printf("Element inserted in the binary search tree\n");
    }
}

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteElement(struct Node *root, int element)
{

    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (element < root->data)
    {
        root->left = deleteElement(root->left, element);
    }
    else if (element > root->data)
    {
        root->right = deleteElement(root->right, element);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteElement(root->left, iPre->data);
    }
    return root;
}

int main()
{
    // the binary search tree:
    //                                           453
    //                      ______________________|________________________
    //                     |                                               |
    //         ___________250__________                      _____________664_____________
    //        |                        |                    |                             |
    //    ___154____             _____342_____        _____623______              _______715_______
    //   |          |           |             |      |              |            |                 |
    //  123        212         335           432    557            650          687               852

    struct Node *root = createNode(453);
    struct Node *left = createNode(250);
    struct Node *right = createNode(664);
    struct Node *left_left = createNode(154);
    struct Node *left_right = createNode(342);
    struct Node *right_left = createNode(623);
    struct Node *right_right = createNode(715);
    struct Node *left_left_left = createNode(123);
    struct Node *left_left_right = createNode(212);
    struct Node *left_right_left = createNode(335);
    struct Node *left_right_right = createNode(432);
    struct Node *right_left_left = createNode(557);
    struct Node *right_left_right = createNode(650);
    struct Node *right_right_left = createNode(687);
    struct Node *right_right_right = createNode(852);

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
        printf("Enter Operation...\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            if (isBST(root))
                printf("Yes, the tree is binary search tree.\n");
            else
                printf("No, the tree is not a binary search tree.\n");
        }
        break;
        case 2:
        {
            printf("The preOrder traversal of the tree is...\n");
            preOrder(root);
        }
        break;
        case 3:
        {
            printf("The inOrder traversal of the tree is...\n");
            inOrder(root);
        }
        break;
        case 4:
        {
            printf("The postOrder traversal of the tree is...\n");
            postOrder(root);
        }
        break;
        case 5:
        {
            int element;
            printf("Enter element to search by Recursion...\n");
            scanf("%d", &element);
            if (searchByRecursion(root, element))
                printf("Element %d is found\n", element);
            else
                printf("Element %d is not found\n", element);
        }
        break;
        case 6:
        {
            int element;
            printf("Enter element to search by Iteration...\n");
            scanf("%d", &element);
            if (searchByIteration(root, element))
                printf("Element %d is found\n", element);
            else
                printf("Element %d is not found\n", element);
        }
        break;
        case 7:
        {
            int element;
            printf("Enter element to insert...\n");
            scanf("%d", &element);
            insertElement(root, element);
        }
        break;
        case 8:
        {
            int element;
            printf("Enter element to delete...\n");
            scanf("%d", &element);
            deleteElement(root, element);
        }
        break;
        }
    }
    return 0;
}