// Given an array prices[] of length N, representing the prices of the stocks on different days,
// the task is to find the maximum profit possible by buying and selling the stocks on different
// days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell.

// Note: Stock must be bought before being sold.


#include <stdio.h>
#include <stdlib.h>

void takeArrayInput(int * arr, int n)
{
    for(int i = 0; i< n; i++)
    {
        printf("Enter price of the day: ");
        scanf("%d", &arr[i]);
    }
}

int main()
{
    //int n = 7;
    //int prices[] = {7, 10, 1, 3, 6, 9, 21};

    int n;
    int * prices;

    printf("Enter number of days: ");
    scanf("%d", &n);

    prices = (int *)(malloc(sizeof(int) * n));

    takeArrayInput(prices, n);

    int maxIndex = 0, minIndex = 0, temp = -1, diff = 0;

    for (int i = 0; i< n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            diff = prices[j] - prices[i];
            if (diff > 0)
            {
                if (prices[j] > prices[maxIndex])
                    maxIndex = j;
                if(prices[i] < prices[minIndex])
                    minIndex = i;
            }
        }
    }

    if(diff > 0)
    {
        printf("Buy stocks for price %d and sell for price %d.\n", prices[minIndex], prices[maxIndex]);
        printf("Profit = %d", diff);
    }
    else
    {
        printf("0 profit can be made.");
    }
}
