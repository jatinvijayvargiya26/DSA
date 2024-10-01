#include <stdio.h>

#define DIM1 2
#define DIM2 2
#define DIM3 2
#define DIM4 2

// Function to input elements of a 4D array
void inputArray(int arr[DIM1][DIM2][DIM3][DIM4]) {
    for (int dim1 = 0; dim1 < DIM1; dim1++) {
        for (int dim2 = 0; dim2 < DIM2; dim2++) {
            for (int dim3 = 0; dim3 < DIM3; dim3++) {
                for (int dim4 = 0; dim4 < DIM4; dim4++) {
                    printf("Enter element [%d][%d][%d][%d]: ", dim1, dim2, dim3, dim4);
                    scanf("%d", &arr[dim1][dim2][dim3][dim4]);
                }
            }
        }
    }
}

// Function to display elements of a 4D array
void displayArray(int arr[DIM1][DIM2][DIM3][DIM4]) {
    printf("The elements are:\n");
    for (int dim1 = 0; dim1 < DIM1; dim1++) {
        for (int dim2 = 0; dim2 < DIM2; dim2++) {
            for (int dim3 = 0; dim3 < DIM3; dim3++) {
                for (int dim4 = 0; dim4 < DIM4; dim4++) {
                    printf("%d\t", arr[dim1][dim2][dim3][dim4]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}

int main() {
    int arr[DIM1][DIM2][DIM3][DIM4] = {0}; // Initialize array with zeros

    inputArray(arr);
    displayArray(arr);

    return 0;
}