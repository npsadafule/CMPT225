#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Lomuto partition scheme with last element as pivot
int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// Hoare partition scheme with first element as pivot
int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

// Median-of-three utility function
int medianOfThree(vector<int>& arr, int a, int b, int c) {
    if ((arr[a] - arr[b]) * (arr[c] - arr[a]) >= 0) return a;
    else if ((arr[b] - arr[a]) * (arr[c] - arr[b]) >= 0) return b;
    else return c;
}

// Quicksort with Lomuto partitioning and median-of-three pivot selection
void quicksortLomutoMedian(vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int med = medianOfThree(arr, low, low + (high - low) / 2, high);
            swap(arr[med], arr[high]); // Median-of-three pivot
            int pivot = lomutoPartition(arr, low, high);
            quicksortLomutoMedian(arr, low, pivot - 1);
            quicksortLomutoMedian(arr, pivot + 1, high);
        }
    }
}

// Quicksort with Hoare partitioning and median-of-three pivot selection
void quicksortHoareMedian(vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int med = medianOfThree(arr, low, low + (high - low) / 2, high);
            swap(arr[med], arr[low]); // Median-of-three pivot
            int pivot = hoarePartition(arr, low, high);
            quicksortHoareMedian(arr, low, pivot);
            quicksortHoareMedian(arr, pivot + 1, high);
        }
    }
}

// Quicksort with Lomuto partitioning and last element as pivot
void quicksortLomuto(vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int pivot = lomutoPartition(arr, low, high);
            quicksortLomuto(arr, low, pivot - 1);
            quicksortLomuto(arr, pivot + 1, high);
        }
    }
}

// Quicksort with Hoare partitioning and first element as pivot
void quicksortHoare(vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int pivot = hoarePartition(arr, low, high);
            quicksortHoare(arr, low, pivot);
            quicksortHoare(arr, pivot + 1, high);
        }
    }
}

// Main function to execute the Quicksort variants
int main() {
    // Random number generation
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 1000000);

    // Reserving space for 100 million integers in 'original' to prevent reallocations
    vector<int> original;
    original.reserve(100000000);

    // Generating large input data
    for (int i = 0; i < 100000000; ++i) {
        original.push_back(dist(rng));
    }

    vector<int> arr;
    chrono::duration<double> elapsed;
    auto start = chrono::high_resolution_clock::now();
    auto finish = chrono::high_resolution_clock::now();

    // sort for comparison
    arr = original; // Copy original data
    start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "sort time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is NOT sorted." << endl;
    }

    // Quicksort with Lomuto and last element pivot
    arr = original;
    start = chrono::high_resolution_clock::now();
    quicksortLomuto(arr, 0, arr.size() - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Quicksort Lomuto with last element as pivot time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is NOT sorted." << endl;
    }

    // Quicksort with Hoare and first element pivot
    arr = original;
    start = chrono::high_resolution_clock::now();
    quicksortHoare(arr, 0, arr.size() - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Quicksort Hoare with first element as pivot time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is NOT sorted." << endl;
    }

    // Quicksort with Lomuto and median-of-three pivot
    arr = original;
    start = chrono::high_resolution_clock::now();
    quicksortLomutoMedian(arr, 0, arr.size() - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Quicksort Lomuto with median-of-three time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is NOT sorted." << endl;
    }

    // Quicksort with Hoare and median-of-three pivot
    arr = original;
    start = chrono::high_resolution_clock::now();
    quicksortHoareMedian(arr, 0, arr.size() - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Quicksort Hoare with median-of-three time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is NOT sorted." << endl;
    }

    return 0;
}