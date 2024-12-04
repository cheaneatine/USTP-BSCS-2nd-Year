#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

void insertionSort(std::vector<int> &arr);
std::vector<int> generateReverseSortedNumbers(int size);
void printNumbers(const std::vector<int> &arr);

void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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

    // Sort numbers using insertion sort
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    // Print sorted numbers
    std::cout << "\nSorted numbers: ";
    printNumbers(numbers);

    // Measure the time taken by Insertion Sort
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nInsertion Sort took " << duration.count() << " ms\n";

    return 0;
}