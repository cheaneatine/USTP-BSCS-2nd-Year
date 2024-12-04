#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <chrono>    // For measuring execution time

void hybridSort(std::vector<int> &arr);
int determineThreshold(int n);
void heapSort(std::vector<int> &arr, int start, int end);
void buildMaxHeap(std::vector<int> &arr, int start, int end);
void maxHeapify(std::vector<int> &arr, int index, int end);
void insertionSort(std::vector<int> &arr, int start, int end);
void enhancedInsertionSort(std::vector<int> &arr, int start, int end);

void hybridSort(std::vector<int> &arr)
{
    int n = arr.size();
    int threshold = determineThreshold(n);
    heapSort(arr, 0, n - 1);
    if (n <= threshold)
    {
        insertionSort(arr, 0, n - 1);
    }
    else
    {
        enhancedInsertionSort(arr, 0, n - 1);
    }
}

int determineThreshold(int n)
{
    return std::max(500000, n / 20);
}

void heapSort(std::vector<int> &arr, int start, int end)
{
    buildMaxHeap(arr, start, end);
    for (int i = end; i > start; --i)
    {
        std::swap(arr[start], arr[i]);
        maxHeapify(arr, start, i - 1);
    }
}

void buildMaxHeap(std::vector<int> &arr, int start, int end)
{
    for (int i = (end - start) / 2; i >= start; --i)
    {
        maxHeapify(arr, i, end);
    }
}

void maxHeapify(std::vector<int> &arr, int index, int end)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left <= end && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= end && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        std::swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, end);
    }
}

void insertionSort(std::vector<int> &arr, int start, int end)
{
    for (int i = start + 1; i <= end; ++i)
    {
        int key = arr[i];
        int left = start;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j > right; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[right + 1] = key;
    }
}

void enhancedInsertionSort(std::vector<int> &arr, int start, int end)
{
    int i = start;
    while (i <= end)
    {
        int run_start = i;
        while (i < end && arr[i] <= arr[i + 1])
        {
            ++i;
        }
        insertionSort(arr, run_start, i);
        ++i;
    }
}

int main()
{
    const int numNumbers = 100; // Specify the number of numbers to sort
    std::vector<int> numbers(numNumbers);

    // Generate a sorted array
    for (int i = 0; i < numNumbers; ++i)
    {
        numbers[i] = i; // Directly assigning sorted numbers
    }

    // Sort numbers using hybrid sort
    hybridSort(numbers);

    // Print sorted numbers
    std::cout << "Sorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Measure the time taken by hybridSort
    auto start = std::chrono::high_resolution_clock::now();
    hybridSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nHybrid Sort took " << duration.count() << " ms\n";

    return 0;
}