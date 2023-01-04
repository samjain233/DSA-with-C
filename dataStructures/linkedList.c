#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListShow(struct Node *ptr)
{
    printf("Elements in the linked list are...\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void circularListShow(struct Node *ptr)
{
    printf("Elements in the linked list are...\n");
    while (1)
    {
        int operation = 0;
        printf("%d\n", ptr->data);
        ptr = ptr->next;
        printf("Enter 1 to show next Element...");
        scanf("%d", &operation);
        if(operation != 1) break;
    }
}

void insertionAtBegining(int data, struct Node *newHead, struct Node *oldHead)
{
    newHead->data = data;
    newHead->next = oldHead;
}

void insertionInBetween(int data, struct Node *left, struct Node *middle, struct Node *right)
{
    middle->data = data;
    left->next = middle;
    middle->next = right;
}

void insertionAtEnd(int data, struct Node *oldEnd, struct Node *newEnd)
{
    newEnd->data = data;
    oldEnd->next = newEnd;
    newEnd->next = NULL;
}

void deletionAtBegining(struct Node *head)
{
    free(head);
}

void deletionInBetween(struct Node *left, struct Node *middle, struct Node *right)
{
    middle->data = 0;
    left->next = right;
    free(middle);
}

void deletionAtEnd(struct Node *left, struct Node *right)
{
    right->data = 0;
    left->next = NULL;
    free(right);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 7;
    fourth->next = NULL;

    linkedListShow(head);

    int operation;
    printf("Enter Operation...\n");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
    {
        struct Node *newNode;
        int data = 0;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        insertionAtBegining(data, newNode, head);
        linkedListShow(newNode);
    }
    break;
    case 2:
    {
        struct Node *newNode;
        int data = 0;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        insertionInBetween(data, third, newNode, fourth);
        linkedListShow(head);
    }
    break;
    case 3:
    {
        struct Node *newNode;
        int data = 0;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        insertionAtEnd(data, fourth, newNode);
        linkedListShow(head);
    }
    break;
    case 4:
    {
        deletionAtBegining(head);
        linkedListShow(second);
    }
    break;
    case 5:
    {
        deletionInBetween(second, third, fourth);
        linkedListShow(head);
    }
    break;
    case 6:
    {
        deletionAtEnd(third, fourth);
        linkedListShow(head);
    }
    break;
    case 7:
    {
        printf("Converting Singly list to Circular list...\n");
        fourth->next = head;
        circularListShow(head);
    }
    break;
    }
    return 0;
}