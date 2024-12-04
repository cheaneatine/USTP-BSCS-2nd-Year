#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

void insertionSort(std::vector<int> &arr);

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

int main()
{
    const int numNumbers = 100; // Specify the number of numbers to sort
    std::vector<int> numbers(numNumbers);

    // Generate a sorted array
    for (int i = 0; i < numNumbers; ++i)
    {
        numbers[i] = i; // Directly assigning sorted numbers
    }

    // Sort numbers using insertion sort
    insertionSort(numbers);

    // Print sorted numbers
    std::cout << "Sorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Measure the time taken by Insertion Sort
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nInsertion Sort took " << duration.count() << " ms\n";

    return 0;
}