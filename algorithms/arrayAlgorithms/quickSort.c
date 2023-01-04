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

int partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }

        while (array[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&array[i], &array[j]);
        }
    } while (i < j);
    swap(&array[low], &array[j]);
    return j;
}

void quickSort(int *array, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    int low = 0;
    int high = sizeof(array) / sizeof(int) - 1;
    quickSort(array, low, high);
    printf("Showing QuickSort Sorted Array...\n");
    showSortedArray(array, sizeof(array) / sizeof(int));
    return 0;
}