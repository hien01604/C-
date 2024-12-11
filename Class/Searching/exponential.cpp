#include <iostream>
#include <algorithm>  // For std::min
using namespace std;

// Binary search function
int binarySearch(int A[], int l, int n, int x) {
    int m;
    int r = n - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (x == A[m]) return m;
        if (x < A[m]) r = m - 1;  // Fixed the incorrect dash here
        else l = m + 1;
    }
    return -1;
}

// Linear search function with attempt logging
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        cout << "Attempt " << i << ": The current number is: " << arr[i] << endl;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Exponential search function
int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x)
        return 0;
    
    int i = 1;
    while (i < n && arr[i] <= x) {
        cout << "The current index is: " << i << endl;
        i = i * 2;
    }
    cout << "The final index to find the target number is: " << i <<endl;
    cout<<"The lower bound is: "<<i/2<<endl;
    cout<<"The upperbound is: :"<<i<<endl;
    return binarySearch(arr, i / 2, min(i, n), x);
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0 ; i < size ; i ++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
    // Ensure array is sorted before performing exponential search
    sort(arr, arr + size);
	for(int i = 0 ; i < size ; i ++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
    int target = 50;
    cout << "Searching number: " << target<<endl;

    int result = exponentialSearch(arr, size, target);
    cout << "The index of targeted number: " << result << endl;
    return 0;
}