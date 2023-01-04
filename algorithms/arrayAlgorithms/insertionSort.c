#include <stdio.h>
#include <stdlib.h>

void showSortedArray(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        printf("%d\n", array[i]);
    }
}

void insertionSort(int *array, int elementsCount)
{
    for (int i = 1; i < elementsCount; i++)
    {
        int j, key = array[i];
        for (j = i - 1; j >= 0 && array[j] > key; j--)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }
    printf("Showing Insertion Sorted Array...\n");
    showSortedArray(array, elementsCount);
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    insertionSort(array, sizeof(array) / sizeof(int));
    return 0;
}