// Inverted Star Pyramid

#include <stdio.h>

int main(){
    int n, count;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    count = n - 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j< i; j++){
            printf(" ");
        }

        for (int k = n - i + count; k >0; k--){
            printf("*");
        }

        printf("\n");
    count--;
    }

}
