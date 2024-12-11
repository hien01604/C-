#include <iostream>
using namespace std;

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int *a, int k, int n) {
    int j = 2 * k + 1; // Left child index
    while (j < n) {
        // Check if the right child exists and is greater than the left child
        if (j + 1 < n && a[j] < a[j + 1]) {
            j = j + 1; // Move to the right child
        }
        // If the parent is already larger than the largest child, stop
        if (a[k] >= a[j]) return;
        // Swap parent with the larger child
        swap(a[k], a[j]);
        // Move down the tree
        k = j;
        j = 2 * k + 1;
    }
}

void buildHeap(int *a, int n) {
    int i = (n - 1) / 2; // Start from the last non-leaf node
    while (i >= 0) {
        heapify(a, i, n);
        cout << "After heapify at index " << i << ": ";
        printArray(a, n);
        i--;
    }
}

void heapSort(int *a, int n) {
    cout << "Building the heap:" << endl;
    buildHeap(a, n);
    cout << "Heap built: ";
    printArray(a, n);
    
    while (n > 0) {
        n = n - 1;
        // Swap the root (max element) with the last element
        swap(a[0], a[n]);
        cout << "After swapping root with index " << n << ": ";
        printArray(a, n + 1);
        // Restore the heap property for the reduced heap
        heapify(a, 0, n);
        cout << "After heapify: ";
        printArray(a, n);
    }
}

int main() {
    int a[] = {10, 3, 5, 8, 2, 6, 1, 4, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    printArray(a, n);

    cout << "\nPerforming heap sort step-by-step:\n";
    heapSort(a, n);

    cout << "\nSorted array: ";
    printArray(a, n);

    return 0;
}
