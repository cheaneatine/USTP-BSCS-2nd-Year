#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <random>    // For random number generation
#include <chrono>    // For measuring execution time

void hybridSort(std::vector<int> &arr);
int determineThreshold(int n);
void heapSort(std::vector<int> &arr, int start, int end);
void buildMaxHeap(std::vector<int> &arr, int start, int end);
void maxHeapify(std::vector<int> &arr, int index, int end);
void insertionSort(std::vector<int> &arr, int start, int end);
void enhancedInsertionSort(std::vector<int> &arr, int start, int end);
std::vector<int> generateRandomNumbers(int size, int minValue, int maxValue);

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
    const int numNumbers = 10; // Specify the number of random numbers to generate and sort
    const int minValue = 0;    // Specify the minimum value for numbers
    const int maxValue = 9999; // Specify the maximum value for numbers

    // Generate a random array
    std::vector<int> numbers = generateRandomNumbers(numNumbers, minValue, maxValue);

    // Print original numbers
    std::cout << "Original numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort numbers using hybrid sort
    hybridSort(numbers);

    // Print sorted numbers
    std::cout << "\nSorted numbers: ";
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
    std::cout << "\n Hybrid Sort took " << duration.count() << " ms\n";

    return 0;
}