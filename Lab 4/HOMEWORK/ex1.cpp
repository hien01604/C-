#include <iostream>
#include <cmath>
using namespace std;

struct Product {
    string name;
    int price;
    float rating;
    int popularity;
};

// Quick Sort
int partition(Product arr[], int low, int high, int (Product::*attribute)) {
    int pivot = arr[high].*attribute;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].*attribute < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Product arr[], int low, int high, int (Product::*attribute)) {
    if (low < high) {
        int pi = partition(arr, low, high, attribute);
        quickSort(arr, low, pi - 1, attribute);
        quickSort(arr, pi + 1, high, attribute);
    }
}

// Merge Sort
void merge(Product arr[], int left, int mid, int right, int (Product::*attribute)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Product* L = new Product[n1];
    Product* R = new Product[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].*attribute <= R[j].*attribute) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Product arr[], int left, int right, int (Product::*attribute)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, attribute);
        mergeSort(arr, mid + 1, right, attribute);
        merge(arr, left, mid, right, attribute);
    }
}

// Heap Sort
void heapify(Product arr[], int n, int i, int (Product::*attribute)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].*attribute > arr[largest].*attribute) largest = left;
    if (right < n && arr[right].*attribute > arr[largest].*attribute) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, attribute);
    }
}

void heapSort(Product arr[], int n, int (Product::*attribute)) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, attribute);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, attribute);
    }
}

// Display Products
void displayProducts(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " - Price: " << arr[i].price 
             << ", Rating: " << arr[i].rating 
             << ", Popularity: " << arr[i].popularity << "\n";
    }
    cout << endl;
}

// Main function
int main() {
    Product products[] = {
        {"Product A", 10, 4.5, 50},
        {"Product B", 15, 4.7, 60},
        {"Product C", 8, 4.3, 70},
        {"Product D", 12, 4.6, 80}
    };
    int n = sizeof(products) / sizeof(products[0]);

    int choice, attributeChoice;
    int (Product::*attribute);

    cout << "Select attribute to sort by:\n";
    cout << "1. Price\n";
    cout << "2. Rating\n";
    cout << "3. Popularity\n";
    cin >> attributeChoice;

    // Set attribute pointer based on choice
    switch (attributeChoice) {
        case 1: attribute = &Product::price; break;
        case 2: attribute = reinterpret_cast<int (Product::*)>(&Product::rating); break;
        case 3: attribute = &Product::popularity; break;
        default: cout << "Invalid choice"; return 0;
    }

    cout << "Select sorting algorithm:\n";
    cout << "1. Quick Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Heap Sort\n";
    cin >> choice;

    switch (choice) {
        case 1:
            quickSort(products, 0, n - 1, attribute);
            cout << "\nProducts sorted by Quick Sort:\n";
            displayProducts(products, n);
            break;

        case 2:
            mergeSort(products, 0, n - 1, attribute);
            cout << "\nProducts sorted by Merge Sort:\n";
            displayProducts(products, n);
            break;

        case 3:
            heapSort(products, n, attribute);
            cout << "\nProducts sorted by Heap Sort:\n";
            displayProducts(products, n);
            break;

        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}
