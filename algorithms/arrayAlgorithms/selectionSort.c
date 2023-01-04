#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void showSortedArray(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        printf("%d\n", array[i]);
    }
}
void selectionSort(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount - 1; i++)
    {
        int minPosition = i;
        for (int j = i + 1; j < elementsCount; j++)
        {
            if (array[j] < array[minPosition])
            {
                minPosition = j;
            }
        }
        swap(&array[i], &array[minPosition]);
    }
    printf("Showing Selection Sorted Array...\n");
    showSortedArray(array, elementsCount);
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    selectionSort(array, sizeof(array) / sizeof(int));
    return 0;
}