#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        return 1;
    else
        return 0;
}

struct Node *push(struct Node *oldTop)
{
    if (isFull())
    {
        printf("Stack is full\n");
        return 0;
    }
    else
    {
        int element;
        printf("Enter element to push...\n");
        scanf("%d", &element);
        struct Node *newTop = (struct Node *)malloc(sizeof(struct Node));
        newTop->data = element;
        newTop->next = oldTop;
        printf("Element pushed to stack\n");
        return newTop;
    }
}

struct Node *pop(struct Node *oldTop)
{
    if (isEmpty(oldTop))
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        int topElement = oldTop->data;
        struct Node *newTop = oldTop->next;
        oldTop->data = 0;
        free(oldTop);
        printf("%d popped from stack\n", topElement);
        return newTop;
    }
}

void getInformation(struct Node *top)
{
    printf("Total Size of Stack: Depend on Heap Memory\n");
    int elementsCount = 0;
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        elementsCount++;
        ptr = ptr->next;
    }

    printf("Used Size of Stack: %d\n", elementsCount);
    if (isEmpty(top))
        printf("Stack is Empty, push is possible, pop is not.\n");
    if (isFull(top))
        printf("Stack is Full, pop is possible, push is not.\n");
}

void traverse(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Elements in Stack are...\n");
        struct Node *ptr = top;
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    struct Node *top = NULL;
    while (1)
    {
        int operation;
        printf("Enter operation...\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            if (isEmpty(top))
                printf("Yes, stack is empty\n");
            else
                printf("No, stack is not empty\n");
        }
        break;

        case 2:
        {
            if (isFull(top))
                printf("Yes, stack is full\n");
            else
                printf("No, stack is not full\n");
        }
        break;
        case 3:
        {
            top = push(top);
        }
        break;
        case 4:
        {
            top = pop(top);
        }
        break;
        case 5:
        {
            getInformation(top);
        }
        break;
        case 6:
        {
            traverse(top);
        }
        break;
        }
    }
    return 0;
}