#include <stdio.h>
#include <string.h>

void insertion_sort(int arr[], int n)
{
    int j, temp;
    for (int i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
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

    display_arr(arr, n, "Array before sort: ");
    insertion_sort(arr, n);
    display_arr(arr, n, "\n\nArray after sort: ");
}