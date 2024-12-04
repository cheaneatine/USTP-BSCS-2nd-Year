#include <iostream>
#include <vector>
#include <random> // For random number generation
#include <chrono> // For measuring execution time

void insertionSort(std::vector<int> &arr);
std::vector<int> generateRandomNumbers(int size, int minValue, int maxValue);

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
    const int numNumbers = 300000; // Specify the number of random numbers to generate and sort
    const int minValue = 0;        // Specify the minimum value for numbers
    const int maxValue = 9999;     // Specify the maximum value for numbers

    std::vector<int> numbers = generateRandomNumbers(numNumbers, minValue, maxValue);

    // Print original numbers
    std::cout << "Original numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(numbers);

    // Print sorted numbers
    std::cout << "\nSorted numbers: ";
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