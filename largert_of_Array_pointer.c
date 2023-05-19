#include <stdio.h>

int findLargestElement(int *arr, int size) {
    int *ptr = arr;
    int largest = *ptr;

    for (int i = 1; i < size; i++) {
        if (*(ptr + i) > largest)
            largest = *(ptr + i);
    }

    return largest;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargestElement(arr, size);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
