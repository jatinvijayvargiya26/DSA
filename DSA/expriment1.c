#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int currentSize = 0;
int array[MAX_SIZE];

// Function to shift elements to the right
void shiftElementsRight(int arr[], int start, int end) {
    for (int i = end; i >= start; i--) {
        arr[i] = arr[i - 1];
    }
}

// Function to add an element at the end of the array
void addEnd(int arr[], int value) {
    if (currentSize < MAX_SIZE) {
        arr[currentSize] = value;
        currentSize++;
    } else {
        printf("Array is full\n");
    }
}

// Function to add an element at the beginning of the array
void addBeginning(int arr[], int value) {
    if (currentSize < MAX_SIZE) {
        shiftElementsRight(arr, 1, currentSize);
        arr[0] = value;
        currentSize++;
    } else {
        printf("Array is full\n");
    }
}

// Function to add an element at a specific index
void addAtIndex(int arr[], int value, int index) {
    if (currentSize < MAX_SIZE && index >= 0 && index <= currentSize) {
        shiftElementsRight(arr, index + 1, currentSize);
        arr[index] = value;
        currentSize++;
    } else {
        printf("Invalid index or array is full\n");
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int value, value1, value2, index;

    array[0] = 1;
    printf("\n");

    printf("Enter a value to add at the end of the array: ");
    scanf("%d", &value);
    addEnd(array, value);
    printArray(array, currentSize);
    printf("\n");

    printf("Enter a value to add at the beginning of the array: ");
    scanf("%d", &value1);
    addBeginning(array, value1);
    printArray(array, currentSize);
    printf("\n");

    printf("Enter a value and index to add at a specific position: ");
    scanf("%d %d", &value2, &index);
    addAtIndex(array, value2, index);
    printArray(array, currentSize);
    printf("\n");

    return 0;
}