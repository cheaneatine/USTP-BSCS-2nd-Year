#include <iostream>
#include <vector>
#include <random> // For random number generation

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
    const int numNumbers = 10;
    const int minValue = 1;
    const int maxValue = 10;

    std::vector<int> numbers = generateRandomNumbers(numNumbers, minValue, maxValue);

    std::cout << "Original numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    heapSort(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}