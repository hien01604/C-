#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Partition function for quicksort (without using swap)
int partitionEndPivot(int arr[], int low, int high) {
    int pivot = arr[high];  // The pivot is the last element
    int i = low;  // Index of smaller element

    // Traverse through the array and rearrange elements around the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // Manually swap arr[i] and arr[j] without using swap()
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    
    // Swap pivot to its correct position
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;  // Return the partition index
}

// Quicksort using the partitionEndPivot method
void quickSortEndPivot(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partitionEndPivot(arr, low, high);
        
        // Recursively apply quicksort on the left and right subarrays
        quickSortEndPivot(arr, low, pi - 1);
        quickSortEndPivot(arr, pi + 1, high);
    }
}

int main() {
    // Sample array to sort
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    // Apply quicksort to the array using the last element as the pivot
    quickSortEndPivot(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
