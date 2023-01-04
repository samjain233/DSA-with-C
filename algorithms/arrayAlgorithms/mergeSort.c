#include <stdio.h>
#include <stdlib.h>

void showSortedArray(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        printf("%d\n", array[i]);
    }
}

void merge(int *array, int mid, int low, int high)
{
    int i, j, k, temp[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = array[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = array[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        array[i] = temp[i];
    }
}

void mergeSort(int *array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, mid, low, high);
    }
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    int low = 0;
    int high = sizeof(array) / sizeof(int) - 1;
    mergeSort(array, low, high);
    printf("Showing MergeSort Sorted Array...\n");
    showSortedArray(array, sizeof(array) / sizeof(int));
    return 0;
}