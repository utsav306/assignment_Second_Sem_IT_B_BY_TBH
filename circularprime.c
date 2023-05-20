#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isCircularPrime(int number) {
    int temp = number;
    int numDigits = 0;

    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    int n = number;
    while (isPrime(n)) {
        int rem = n % 10;
        int div = n / 10;
        n = rem * pow(10, numDigits - 1) + div;

        if (n == number) {
            return true;
        }
    }

    return false;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isCircularPrime(number)) {
        printf("%d is a circular prime.\n", number);
    } else {
        printf("%d is not a circular prime.\n", number);
    }

    return 0;
}
