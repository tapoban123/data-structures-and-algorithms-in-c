#include <stdio.h>
#include <string.h>

void bubble_sort(int arr[], int n)
{
    int temp, did_swap;
    for (int i = n - 1; i >= 1; i--)
    {
        did_swap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_swap = 1;
            }
        }

        if (did_swap == 0)
            break;
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

    display_arr(arr, n, "Array before sort: ");
    bubble_sort(arr, n);
    display_arr(arr, n, "\nArray after sort: ");
}