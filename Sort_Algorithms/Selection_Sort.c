// Get the minimum & swap it.

#include <stdio.h>
#include <string.h>

void selection_sort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void display_arr(int arr[], int n, char heading[])
{
    puts(heading);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n = 6;
    int arr[] = {9, 5, 6, 2, 9, 7};

    display_arr(arr, n, "Array before sorting: ");
    selection_sort(arr, n);
    display_arr(arr, n, "\n\nArray after sorting: ");
}