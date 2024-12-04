#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    // Seed for random number generation
    srand(time(0));

    // Generate a large vector with random integers
    int size = 100; // Adjust the size as needed
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

    int comparisons_heap = heapSort(arr);

    cout << "\nSorted array using Heap Sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}