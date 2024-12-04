#include <iostream>
#include <vector>
#include <random> // For random number generation

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

    insertionSort(numbers);

    std::cout << "Sorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}