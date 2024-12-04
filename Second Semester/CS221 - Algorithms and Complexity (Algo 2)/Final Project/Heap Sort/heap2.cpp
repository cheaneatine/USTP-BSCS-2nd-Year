#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

void heapSort(std::vector<int> &arr);
void buildMaxHeap(std::vector<int> &arr);
void maxHeapify(std::vector<int> &arr, int index, int heapSize);

void heapSort(std::vector<int> &arr)
{
    buildMaxHeap(arr);
    for (int i = arr.size() - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

void buildMaxHeap(std::vector<int> &arr)
{
    int heapSize = arr.size();
    for (int i = heapSize / 2 - 1; i >= 0; --i)
    {
        maxHeapify(arr, i, heapSize);
    }
}

void maxHeapify(std::vector<int> &arr, int index, int heapSize)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < heapSize && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        std::swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, heapSize);
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

    // Sort numbers using heap sort
    heapSort(numbers);

    // Print sorted numbers
    std::cout << "\nSorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Measure the time taken by Heap Sort
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nHeap Sort took " << duration.count() << " ms\n";

    return 0;
}