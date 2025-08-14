#include <stdio.h>

struct Element
{
    int ele;
    int count;
};

void displayArr(int arr[], int n)
{
    printf("Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int hash[1000], arr[n];
    struct Element maxEle = {0, 0}, minEle = {0, 0};


    // ! Algorithm needs rework.

    for (int i = 0; i < n; i++)
    {
        printf("Enter an element: ");
        scanf("%d", &arr[i]);

        hash[arr[i]]++;

        if (hash[arr[i]] > maxEle.count)
        {
            maxEle.count = hash[arr[i]];
            maxEle.ele = arr[i];
        }

        if (hash[arr[i]] < minEle.count)
        {
            minEle.ele = arr[i];
            minEle.count = hash[arr[i]];
        }
    }

    displayArr(arr, n);

    printf("\n\nElement with Maximum frequency = %d", maxEle.ele);
    printf("\nElement with Minimum frequency = %d", minEle.ele);
}