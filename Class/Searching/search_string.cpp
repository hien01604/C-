#include <iostream>
#include <cmath>   // For sqrt in Jump Search
#include <string>  // For string operations
using namespace std;

// Linear Search
int linearSearch(string arr[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;  // Found
    }
    return -1;  // Not found
}

// Binary Search
int binarySearch(string arr[], int left, int right, string target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;         // Found
        else if (arr[mid] < target) left = mid + 1; // Search right half
        else right = mid - 1;                      // Search left half
    }
    return -1;  // Not found
}

// Jump Search
int jumpSearch(string arr[], int size, string target) {
    int step = sqrt(size);
    int prev = 0;

    // Find the block containing the target
    while (arr[min(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) return -1;  // Not found
    }

    // Linear search within the block
    for (int i = prev; i < min(step, size); i++) {
        if (arr[i] == target) return i;  // Found
    }
    return -1;  // Not found
}

// Interpolation Search
int interpolationSearch(string arr[], int size, string target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;  // Found
            return -1;                           // Not found
        }

        // Estimate the position using interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] > arr[low] ? arr[high][0] - arr[low][0] : 1)) *
                          (target[0] - arr[low][0]);

        if (arr[pos] == target) return pos;      // Found
        else if (arr[pos] < target) low = pos + 1; // Search right
        else high = pos - 1;                     // Search left
    }
    return -1;  // Not found
}

// Exponential Search
int exponentialSearch(string arr[], int size, string target) {
    if (arr[0] == target) return 0;  // First element

    // Find the range
    int bound = 1;
    while (bound < size && arr[bound] <= target) {
        bound *= 2;
    }

    // Binary search within the range
    return binarySearch(arr, bound / 2, min(bound, size - 1), target);
}

// Main Function for Testing
int main() {
    // Sorted array of strings
    string arr[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);

    string target;
    cout << "Enter the string to search: ";
    cin >> target;

    // Test Linear Search
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1)
        cout << "Linear Search: Found at index " << linearResult << endl;
    else
        cout << "Linear Search: Not found" << endl;

    // Test Binary Search
    int binaryResult = binarySearch(arr, 0, size - 1, target);
    if (binaryResult != -1)
        cout << "Binary Search: Found at index " << binaryResult << endl;
    else
        cout << "Binary Search: Not found" << endl;

    // Test Jump Search
    int jumpResult = jumpSearch(arr, size, target);
    if (jumpResult != -1)
        cout << "Jump Search: Found at index " << jumpResult << endl;
    else
        cout << "Jump Search: Not found" << endl;

    // Test Interpolation Search
    int interpolationResult = interpolationSearch(arr, size, target);
    if (interpolationResult != -1)
        cout << "Interpolation Search: Found at index " << interpolationResult << endl;
    else
        cout << "Interpolation Search: Not found" << endl;

    // Test Exponential Search
    int exponentialResult = exponentialSearch(arr, size, target);
    if (exponentialResult != -1)
        cout << "Exponential Search: Found at index " << exponentialResult << endl;
    else
        cout << "Exponential Search: Not found" << endl;

    return 0;
}
