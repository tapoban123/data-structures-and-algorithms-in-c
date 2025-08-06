#include <stdio.h>

void displayArr(int arr[], int n)
{
    printf("\nElements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[100] = {0};
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int inputArr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter an element between 0 and 100: ");
        scanf("%d", &inputArr[i]);
        
        arr[inputArr[i]]++;
    }

    displayArr(inputArr, n);

    int query;
    int keepRunning = 1;

    while (keepRunning)
    {
        printf("\nEnter the element whose count you want to know: ");
        scanf("%d", &query);

        printf("%d is present %d times in the array.", query, arr[query]);

        printf("Do you want to continue? (0/1) ");
        scanf("%d", &keepRunning);
    }
}