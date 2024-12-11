#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to print the current state of the array
void printArray(int *a, int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void quickSort(int *a, int b, int e) {
    if (b >= e) return;

    int pivot = a[b];  // Choose the pivot as the first element in the current range
    int i = b, j = e;

    cout << "Pivot: " << pivot << " - Starting partitioning from index " << b << " to " << e << endl;

    // Partition the array
    while (i <= j) {  // Use <= to correctly handle meeting point of i and j
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {  // Swap and then increment/decrement to move towards center
            swap(a[i], a[j]);
            cout << "Swapped " << a[i] << " and " << a[j] << ": ";
            printArray(a, e + 1); // Print the array after each swap
            i++;
            j--;
        }
    }

    // Recurse on the two halves
    quickSort(a, b, j);
    quickSort(a, i, e);
}

void input(int arr[], int n){
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);
    

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
