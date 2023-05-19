#include <stdio.h>

int isSpyNumber(int num) {
    int sum = 0, product = 1;
    
    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }
    
    return (sum == product);
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isSpyNumber(number))
        printf("%d is a spy number.\n", number);
    else
        printf("%d is not a spy number.\n", number);

    return 0;
}
