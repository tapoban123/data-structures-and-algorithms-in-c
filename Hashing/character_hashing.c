#include <stdio.h>
#include <string.h>

int main()
{
    char strValue[50];
    printf("Enter a string: ");
    fgets(strValue, sizeof(strValue), stdin);
    puts(strValue);

    int i = 0, ascii;
    int hash[128] = {0};

    while (strValue[i] != '\0')
    {
        ascii = strValue[i];
        hash[ascii]++;
        i++;
    }

    // for (int i = 0; i < 128; i++)
    // {
    //     if (hash[i] > 0)
    //         printf("%d -> %c -> %d\n", i, i, hash[i]);
    // }

    char query;
    printf("Enter the character you want to search: ");
    scanf("%c", &query);

    printf("%c is present %d times in the string.", query, hash[(int)query]);
}