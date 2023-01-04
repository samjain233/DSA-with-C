#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *array;
};

int isEmpty(struct Queue *queue)
{
    if (queue->front == queue->rear)
        return 1;
    else
        return 0;
}

int isFull(struct Queue *queue)
{
    if (queue->size - queue->rear == 1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *queue)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        int element;
        printf("Enter element to push...\n");
        scanf("%d", &element);
        queue->rear++;
        queue->array[queue->rear] = element;
        printf("Element pushed to stack\n");
    }
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        int frontElement = queue->array[queue->front + 1];
        queue->array[queue->front + 1] = 0;
        queue->front++;
        printf("%d popped from queue\n", frontElement);
        return frontElement;
    }
}

void getInformation(struct Queue *queue)
{
    printf("Total Size of Queue: %d\n", queue->size);
    printf("Used Size of queue: %d\n", queue->rear + 1);
    if (isEmpty(queue))
        printf("Queue is Empty, push is possible, pop is not.\n");
    if (isFull(queue))
        printf("Queue is Full, pop is possible, push is not.\n");
}

void traverse(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Elements in queue are...\n");
        for (int i = queue->front + 1; i <= queue->rear; i++)
        {
            printf("%d\n", queue->array[i]);
        }
    }
}

int main()
{
    struct Queue queue;
    queue.size = 10;
    queue.front = -1;
    queue.rear = -1;
    queue.array = (int *)malloc(queue.size * sizeof(int));
    while (1)
    {
        int operation;
        printf("Enter operation...\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            if (isEmpty(&queue))
                printf("Yes, queue is empty\n");
            else
                printf("No, queue is not empty\n");
        }
        break;

        case 2:
        {
            if (isFull(&queue))
                printf("Yes, queue is full\n");
            else
                printf("No, queue is not full\n");
        }
        break;
        case 3:
        {
            enqueue(&queue);
        }
        break;
        case 4:
        {
            dequeue(&queue);
        }
        break;
        case 5:
        {
            getInformation(&queue);
        }
        break;
        case 6:
        {
            traverse(&queue);
        }
        break;
        }
    }
    return 0;
}