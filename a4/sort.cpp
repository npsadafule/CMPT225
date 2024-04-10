#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Function to perform Insertion Sort
void insertionSort(std::vector<int>& arr, int left, int right) {
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
int lomutoPartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

// Hoare partition scheme with first element as pivot
int hoarePartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

// Median-of-three utility function
int medianOfThree(std::vector<int>& arr, int a, int b, int c) {
    if ((arr[a] - arr[b]) * (arr[c] - arr[a]) >= 0) return a;
    else if ((arr[b] - arr[a]) * (arr[c] - arr[b]) >= 0) return b;
    else return c;
}

// Quicksort with Lomuto partitioning and median-of-three pivot selection
void quicksortLomutoMedian(std::vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int med = medianOfThree(arr, low, low + (high - low) / 2, high);
            std::swap(arr[med], arr[high]); // Median-of-three pivot
            int pivot = lomutoPartition(arr, low, high);
            quicksortLomutoMedian(arr, low, pivot - 1);
            quicksortLomutoMedian(arr, pivot + 1, high);
        }
    }
}

// Quicksort with Hoare partitioning and median-of-three pivot selection
void quicksortHoareMedian(std::vector<int>& arr, int low, int high) {
    if (high - low < 10) { // Threshold for small sequences
        insertionSort(arr, low, high);
    } else {
        if (low < high) {
            int med = medianOfThree(arr, low, low + (high - low) / 2, high);
            std::swap(arr[med], arr[low]); // Median-of-three pivot
            int pivot = hoarePartition(arr, low, high);
            quicksortHoareMedian(arr, low, pivot);
            quicksortHoareMedian(arr, pivot + 1, high);
        }
    }
}

// Quicksort with Lomuto partitioning and last element as pivot
void quicksortLomuto(std::vector<int>& arr, int low, int high) {
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
void quicksortHoare(std::vector<int>& arr, int low, int high) {
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
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000000);

    // Generate large input data
    std::vector<int> original;
    for (int i = 0; i < 100000000; ++i) {
        original.push_back(dist(rng));
    }

    std::vector<int> arr;
    std::chrono::duration<double> elapsed;
    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    // std::sort for comparison
    arr = original; // Copy original data
    start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "std::sort time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array is sorted." << std::endl;
    } else {
        std::cout << "Array is NOT sorted." << std::endl;
    }

    // Quicksort with Lomuto and last element pivot
    arr = original;
    start = std::chrono::high_resolution_clock::now();
    quicksortLomuto(arr, 0, arr.size() - 1);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Quicksort Lomuto with last element as pivot time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array is sorted." << std::endl;
    } else {
        std::cout << "Array is NOT sorted." << std::endl;
    }

    // Quicksort with Hoare and first element pivot
    arr = original;
    start = std::chrono::high_resolution_clock::now();
    quicksortHoare(arr, 0, arr.size() - 1);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Quicksort Hoare with first element as pivot time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array is sorted." << std::endl;
    } else {
        std::cout << "Array is NOT sorted." << std::endl;
    }

    // Quicksort with Lomuto and median-of-three pivot
    arr = original;
    start = std::chrono::high_resolution_clock::now();
    quicksortLomutoMedian(arr, 0, arr.size() - 1);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Quicksort Lomuto with median-of-three time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array is sorted." << std::endl;
    } else {
        std::cout << "Array is NOT sorted." << std::endl;
    }

    // Quicksort with Hoare and median-of-three pivot
    arr = original;
    start = std::chrono::high_resolution_clock::now();
    quicksortHoareMedian(arr, 0, arr.size() - 1);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Quicksort Hoare with median-of-three time: " << elapsed.count() << " s\n";

    // Verify that the array is actually sorted
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array is sorted." << std::endl;
    } else {
        std::cout << "Array is NOT sorted." << std::endl;
    }

    return 0;
}