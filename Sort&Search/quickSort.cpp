#include<iostream>
using namespace std;

// Function to swap values
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function: places pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // picking last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]); // move pivot to its correct position
    return (i + 1);              // return index of pivot
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main
int main() {
    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(arr, size);

    return 0;
}
