#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int prime = 1;
    for (int i = 1; i <= number; i++) {
        if (i != 1) {
            if (number % i == 0 && i != number) {
                prime = 0;
            }
        }
    }

    if (prime == 0) {
        printf("%d is not a prime number", number);
    } else {
        printf("%d is a prime number", number);
    }
    return 0;
}
