#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *createNode(int data)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
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

int getHeight(struct Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalanceFactor(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
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

    // the left rotate function:
    //               x                                                                         y
    //     __________|__________                                                     __________|___________
    //    |                     |                   left rotate                     |                      |
    //    T1            ________y__________       -------------->         __________x___________           T3
    //                 |                   |                             |                      |
    //                 T2                  T3                            T1                     T2

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

    // the right rotate function:
    //                           y                                                          x              
    //                 __________|___________                                     __________|__________       
    //                |                      |                                   |                     |        
    //      __________x___________           T3           right rotate           T1            ________y__________
    //     |                      |                     --------------->                      |                   |                   
    //     T1                     T2                                                          T2                  T3  

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node* insertElement(struct Node *node, int element)
{
    if (node == NULL)
        return createNode(element);

    if (element < node->data)
        node->left = insertElement(node->left, element);
    else if (element > node->data)
        node->right = insertElement(node->right, element);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1 && element < node->left->data)                // left left case
    {
        return rightRotate(node);
    }

    if (bf < -1 && element > node->right->data)              // right right case
    {
        return leftRotate(node);
    }

    if (bf > 1 && element > node->left->data)                // left right case
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && element < node->right->data)              // right left case
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main()
{
    // the avl tree:
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
            printf("The preOrder traversal of the tree is...\n");
            preOrder(root);
        }
        break;
        case 2:
        {
            printf("The inOrder traversal of the tree is...\n");
            inOrder(root);
        }
        break;
        case 3:
        {
            printf("The postOrder traversal of the tree is...\n");
            postOrder(root);
        }
        break;
        case 4:
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
        case 5:
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
        case 6:
        {
            int element;
            printf("Enter element to insert...\n");
            scanf("%d", &element);
            root = insertElement(root, element);
        }
        break;
        }
    }
    return 0;
}