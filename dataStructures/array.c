#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    printf("Elements in the array are...\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element at %d index: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void insertion(struct myArray *a)
{
    int position, element;
    printf("Enter position...\n");
    scanf("%d", &position);
    if (position >= a->total_size)
    {
        printf("Error: position exceeded array size\n");
        return;
    }
    else if (a->used_size == a->total_size)
    {
        printf("Array is full\n");
        return;
    }
    printf("Enter element...\n");
    scanf("%d", &element);
    if (position > a->used_size)
    {
        printf("Position exceeded used size, stacking element at the end...\n");
        (a->ptr)[(a->used_size)] = element;
        (a->used_size)++;
        show(a);
    }
    else if (position <= a->used_size)
    {
        for (int i = a->used_size; i >= position; i--)
        {
            (a->ptr)[i] = (a->ptr)[i - 1];
        }
        (a->ptr)[position - 1] = element;
        (a->used_size)++;
        show(a);
    }
}

void deletion(struct myArray *a)
{
    int position;
    printf("Enter position to delete...\n");
    scanf("%d", &position);
    if (position > a->used_size)
    {
        printf("Element does not exist in array\n");
    }
    else
    {
        for (int i = position; i < a->used_size; i++)
        {
            (a->ptr)[i - 1] = (a->ptr)[i];
        }
        (a->ptr)[(a->used_size) - 1] = 0;
        a->used_size--;
    }
    show(a);
}

int main()
{
    int operation;
    struct myArray marks;
    createArray(&marks, 10, 5);
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};

    while (1)
    {
        printf("Enter operation...\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            printf("We are running setVal now...\n");
            setVal(&marks);
        }
        break;
        case 2:
        {
            printf("We are running show now...\n");
            show(&marks);
        }
        break;
        case 3:
        {
            printf("We are running insertion...\n");
            insertion(&marks);
        }
        break;
        case 4:
        {
            deletion(&marks);
        }
        break;
        }
    }
    return 0;
}