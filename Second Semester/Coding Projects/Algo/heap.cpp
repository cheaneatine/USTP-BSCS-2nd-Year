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
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array:" << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int comparisons_heap = heapSort(arr);

    cout << "Sorted array using Heap Sort:" << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of comparisons made by Heap Sort: " << comparisons_heap << endl;

    return 0;
}