#include <stdio.h>

void rotateArray(int arr[], int n, int d)
{
    // Create a temporary array
    int temp[d];
    
    // Copy the first d elements to the temporary array
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];
    
    // Shift the remaining elements of arr[]
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];
    
    // Copy the elements from the temporary array to the end of arr[]
    for (int i = 0; i < d; i++)
        arr[n - d + i] = temp[i];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;  // Rotate array by 2 positions
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    rotateArray(arr, n, d);
    
    printf("\nRotated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}