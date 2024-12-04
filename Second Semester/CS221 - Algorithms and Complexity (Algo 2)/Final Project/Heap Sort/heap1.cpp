#include <iostream>
#include <vector>
#include <random> // For random number generation
#include <chrono> // For measuring execution time

void heapSort(std::vector<int> &arr);
void buildMaxHeap(std::vector<int> &arr);
void maxHeapify(std::vector<int> &arr, int index, int heapSize);
std::vector<int> generateRandomNumbers(int size, int minValue, int maxValue);

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

std::vector<int> generateRandomNumbers(int size, int minValue, int maxValue)
{
    std::vector<int> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);

    for (int i = 0; i < size; ++i)
    {
        numbers.push_back(dis(gen));
    }

    return numbers;
}

int main()
{
    const int numNumbers = 1000000; // Specify the number of random numbers to generate and sort
    const int minValue = 0;         // Specify the minimum value for numbers
    const int maxValue = 9999;      // Specify the maximum value for numbers

    std::vector<int> numbers = generateRandomNumbers(numNumbers, minValue, maxValue);

    // Print original numbers
    std::cout << "Original numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

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