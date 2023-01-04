#include <stdio.h>
#include <stdlib.h>

void showSortedArray(int *array, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        printf("%d\n", array[i]);
    }
}

int maxElement(int *array, int elementsCount)
{
    int maxElement = 0;
    for (int i = 0; i < elementsCount; i++)
    {
        if (maxElement < array[i])
        {
            maxElement = array[i];
        }
    }
    return maxElement;
}

void countSort(int *array, int elementsCount)
{
    int countArrayLength = maxElement(array, elementsCount) + 1;
    int count[countArrayLength];
    for (int i = 0; i < countArrayLength; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < elementsCount; i++)
    {
        count[array[i]]++;
    }
    int countIndex = 0;
    int mainIndex = 0;

    while (countIndex <= countArrayLength)
    {
        if (count[countIndex] > 0)
        {
            array[mainIndex] = countIndex;
            count[countIndex]--;
            mainIndex++;
        }
        else
        {
            countIndex++;
        }
    }
}

int main()
{
    int array[] = {23, 13, 17, 39, 79, 19, 45, 37, 76, 43, 21, 65, 34, 39, 45, 13};
    countSort(array, sizeof(array) / sizeof(int));
    printf("Showing CountSort Sorted Array...\n");
    showSortedArray(array, sizeof(array) / sizeof(int));
    return 0;
}