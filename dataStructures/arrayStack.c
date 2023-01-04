#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *array;
};

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *stack)
{
    if (stack->size - stack->top == 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *stack)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        int element;
        printf("Enter element to push...\n");
        scanf("%d", &element);
        stack->top++;
        stack->array[stack->top] = element;
        printf("Element pushed to stack\n");
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        int topElement = stack->array[stack->top];
        stack->array[stack->top] = 0;
        stack->top--;
        printf("%d popped from stack\n", topElement);
        return topElement;
    }
}

void getInformation(struct Stack *stack)
{
    printf("Total Size of Stack: %d\n", stack->size);
    printf("Used Size of Stack: %d\n", stack->top + 1);
    if (isEmpty(stack))
        printf("Stack is Empty, push is possible, pop is not.\n");
    if (isFull(stack))
        printf("Stack is Full, pop is possible, push is not.\n");
}

void traverse(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Elements in Stack are...\n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%d\n", stack->array[i]);
        }
    }
}

void peek(struct Stack *stack)
{
    int position;
    printf("Enter position to peek...\n");
    scanf("%d", &position);
    if (position - stack->top > 1)
    {
        printf("Position is empty\n");
        return;
    }
    else
    {
        printf("Elements at %d position is...%d\n", position, stack->array[position - 1]);
    }
}

void stackTop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("stackTop is...%d\n", stack->array[stack->top]);
    }
}

void stackBottom(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("stackBottom is...%d\n", stack->array[0]);
    }
}

int main()
{
    struct Stack stack;
    stack.size = 10;
    stack.top = -1;
    stack.array = (int *)malloc(stack.size * sizeof(int));
    while (1)
    {
        int operation;
        printf("Enter operation...\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            if (isEmpty(&stack))
                printf("Yes, stack is empty\n");
            else
                printf("No, stack is not empty\n");
        }
        break;

        case 2:
        {
            if (isFull(&stack))
                printf("Yes, stack is full\n");
            else
                printf("No, stack is not full\n");
        }
        break;
        case 3:
        {
            push(&stack);
        }
        break;
        case 4:
        {
            pop(&stack);
        }
        break;
        case 5:
        {
            getInformation(&stack);
        }
        break;
        case 6:
        {
            traverse(&stack);
        }
        break;
        case 7:
        {
            peek(&stack);
        }
        break;
        case 8:
        {
            stackTop(&stack);
        }
        break;
        case 9:
        {
            stackBottom(&stack);
        }
        break;
        }
    }
    return 0;
}