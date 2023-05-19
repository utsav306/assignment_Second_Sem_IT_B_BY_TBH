#include <stdio.h>

int isHarshadNumber(int num) {
    int sum = 0;
    int temp = num;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    return (num % sum == 0);
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isHarshadNumber(number))
        printf("%d is a Harshad number.\n", number);
    else
        printf("%d is not a Harshad number.\n", number);

    return 0;
}
