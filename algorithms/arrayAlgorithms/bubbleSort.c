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

void bubbleSort(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount - 1; i++)
    {
        printf("Current pass number... %d\n", i + 1);
        for (int j = 0; j < elementsCount - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    printf("Showing Bubble Sorted Array...\n");
    showSortedArray(array, elementsCount);
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    bubbleSort(array, sizeof(array) / sizeof(int));
    return 0;
}