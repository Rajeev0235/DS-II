#include <stdio.h>

#define SIZE 3

void rotateArray(int arr[SIZE][SIZE]) {
    // Transpose the array
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Reverse each row
    for (int i = 0; i < SIZE; i++) {
        int left = 0;
        int right = SIZE - 1;
        while (left < right) {
            int temp = arr[i][left];
            arr[i][left] = arr[i][right];
            arr[i][right] = temp;
            left++;
            right--;
        }
    }
}

void printArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original array:\n");
    printArray(arr);

    rotateArray(arr);

    printf("Rotated array:\n");
    printArray(arr);

    return 0;
}