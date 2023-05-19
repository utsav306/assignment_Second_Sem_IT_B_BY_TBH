#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex num1, struct Complex num2);

int main() {
    struct Complex num1, num2, sum;

    printf("Enter the first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imaginary);

    printf("\nEnter the second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imaginary);

    sum = addComplex(num1, num2);

    printf("\nSum of the two complex numbers: %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;

    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;

    return sum;
}
