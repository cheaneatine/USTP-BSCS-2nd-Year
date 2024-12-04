#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int LEVEL_THRESHOLD = 10; // Threshold value for switching between insertion sort and heap sort

// Insertion Sort
int insertionSort(vector<int> &arr)
{
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// Heap Sort
int heapify(vector<int> &arr, int n, int i)
{
    int comparisons = 0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        comparisons++;
        comparisons += heapify(arr, n, largest);
    }
    return comparisons;
}

int heapSort(vector<int> &arr)
{
    int comparisons = 0;
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        comparisons += heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        comparisons++;
        comparisons += heapify(arr, i, 0);
    }
    return comparisons;
}

// Hybrid Sort
int hybridSort(vector<int> &arr)
{
    if (arr.size() <= LEVEL_THRESHOLD)
    {
        return insertionSort(arr);
    }
    else
    {
        return heapSort(arr);
    }
}

int main()
{
    // Seed for random number generation
    srand(time(0));

    // Generate a large array with random values
    int size = 10000; // Adjust the size as needed
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000; // Random values between 0 and 9999
    }

    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int comparisons_hybrid = hybridSort(arr);

    cout << "\nSorted array using Hybrid Sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}