#include <stdio.h>

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter the array elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int n;
    printf("Enter the number of rotations: ");
    scanf("%d", &n);

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int j, last;
        last = arr[length - 1];
        for (j = length - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last;
    }

    printf("\n");

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}