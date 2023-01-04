#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void linkedListShow(struct Node *ptr)
{
    printf("Elements in the linked list are...\n");
    while (ptr != NULL)
    {
        int operation = 0;
        printf("%d\n", ptr->data);
        printf("Enter -1 or 1 to go left or right respectively...");
        scanf("%d", &operation);
        if(operation == -1) ptr = ptr->prev;
        else if(operation == 1) ptr = ptr->next;
        else break;
    }
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

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 3;
    second->next = third;

    third->prev = second;
    third->data = 5;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 7;
    fourth->next = NULL;

    linkedListShow(head);

    return 0;
}