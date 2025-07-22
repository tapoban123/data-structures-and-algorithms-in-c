// Given an unsorted array arr[] of size n.
// containing elements from the range 1 to n,
// it is known that one number in this range is missing, and another number occurs twice in the array,
// find both the duplicate number and the missing number.

#include <stdio.h>
#include <stdlib.h>

struct Duplicates
{
    int value;
    int count;
};

void takeArrayInput(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter an element: ");
        scanf("%d", &arr[i]);
    }
}

int isExist(struct Duplicates *duplicates, int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (duplicates[i].value == element)
        {
            return i;
        }
    }
    return -1;
}

void checkDuplicatesAndInsert(struct Duplicates *duplicates, int element, int n)
{
    int index = isExist(duplicates, element, n);
    if (index != -1)
    {
        duplicates[index].count += 1;
        return;
    }
    else
    {
        int newDuplicateIndex;
        if (duplicates[n - 1].value == 0)
        {
            newDuplicateIndex = n - 1;
        }
        else
        {
            newDuplicateIndex = n;
        }
        duplicates[newDuplicateIndex].value = element;
        duplicates[newDuplicateIndex].count = 1;
    }
}

int main()
{
    // int n = 10;
    // int elements[] = {9, 10, 1, 3, 3, 4, 4, 4, 7, 8};
    int n;
    int *elements;
    struct Duplicates duplicates[100] = {};

    printf("Enter the value of n: ");
    scanf("%d", &n);

    elements = (int *)malloc(sizeof(int) * n);
    takeArrayInput(elements, n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        checkDuplicatesAndInsert(duplicates, elements[i], i);
    }
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        int index = isExist(duplicates, i, n);
        if (index == -1)
        {
            while (j < n)
            {
                if (duplicates[j].value == 0)
                {
                    duplicates[j].value = i;
                    duplicates[j].count = 0;
                    break;
                }
                j++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (duplicates[i].count > 1)
        {
            printf("%d is present %d times.\n", duplicates[i].value, duplicates[i].count);
        }
        else if (duplicates[i].count == 0)
        {
            printf("%d is missing.\n", duplicates[i].value);
        }
    }
}
