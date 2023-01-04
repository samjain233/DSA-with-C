#include <stdio.h>
#include <stdlib.h>

// the graph:
//                        0 • • • • • • 1
//                        • •           •
//                        •   •         •
//                        •     •       •
//                        •       •     •
//                        •         •   •
//                        3 • • • • • • 2
//                         •           •
//                          •         •
//                           •       •
//                            •     •
//                             •   •
//                               4
//                             •   •
//                            •     •
//                           •       •
//                          •         •
//                         •           •
//                        •             •
//                       5               6

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

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

void enqueue(struct Queue *queue, int element)
{
    if (isFull(queue))
    {
        return;
    }
    else
    {
        queue->rear++;
        queue->array[queue->rear] = element;
    }
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }
    else
    {
        int frontElement = queue->array[queue->front + 1];
        queue->array[queue->front + 1] = 0;
        queue->front++;
        return frontElement;
    }
}

void depthFirstSearch(int i)
{
    printf("%d\n", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            depthFirstSearch(j);
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

    int operation;
    printf("Enter Operation...\n");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
    {
        printf("The Breadth-First Search traversal of the graph is...\n");
        int node;
        int startingElement = 0;
        printf("%d\n", startingElement);
        visited[startingElement] = 1;
        enqueue(&queue, startingElement); // Enqueue the element for exploration
        while (!isEmpty(&queue))
        {
            int node = dequeue(&queue);
            for (int j = 0; j < 7; j++)
            {
                if (a[node][j] == 1 && visited[j] == 0)
                {
                    printf("%d\n", j);
                    visited[j] = 1;
                    enqueue(&queue, j);
                }
            }
        }
    }
    break;

    case 2:
    {
        printf("The Depth-First Search traversal of the graph is...\n");
        depthFirstSearch(0);
    }
    break;
    }

    return 0;
}