#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

void heapSort(std::vector<int> &arr);
void buildMaxHeap(std::vector<int> &arr);
void maxHeapify(std::vector<int> &arr, int index, int heapSize);
std::vector<int> generateReverseSortedNumbers(int size);
void printNumbers(const std::vector<int> &arr);

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

std::vector<int> generateReverseSortedNumbers(int size)
{
    std::vector<int> numbers(size);
    for (int i = 0; i < size; ++i)
    {
        numbers[i] = size - i; // Assign numbers in reverse sorted order
    }
    return numbers;
}

void printNumbers(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const int numNumbers = 100; // Specify the number of numbers to sort

    // Generate a reverse sorted array
    std::vector<int> numbers = generateReverseSortedNumbers(numNumbers);

    // Print original numbers (optional)
    std::cout << "Original numbers: ";
    printNumbers(numbers);

    // Sort numbers using heap sort
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    // Print sorted numbers
    std::cout << "\nSorted numbers: ";
    printNumbers(numbers);

    // Measure the time taken by Heap Sort
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nHeap Sort took " << duration.count() << " ms\n";

    return 0;
}