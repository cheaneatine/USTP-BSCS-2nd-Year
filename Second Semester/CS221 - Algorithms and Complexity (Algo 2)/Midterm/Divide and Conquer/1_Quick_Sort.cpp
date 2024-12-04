#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements in an array
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to find median of three elements
int medianOfThree(vector<int> &arr, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    return mid;
}

// Function to partition the array using median of three pivot
int partition(vector<int> &arr, int left, int right)
{
    int pivotIndex = medianOfThree(arr, left, right);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Quick sort function
void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main()
{
    vector<int> arr = {8, 2, 4, 9, 1, 7, 5};

    cout << "Given array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

/*

Best Case: O(n log n) - When the median of three pivot selection strategy is
effectively splitting the array into two nearly equal halves in each recursive call.

Average Case: O(n log n) - Same as the best case.

Worst Case: O(n^2) - This can happen when the selected pivot is always the smallest
or largest element in the array, leading to highly unbalanced partitions. However,
the median of three strategy significantly reduces the probability of this worst-case
scenario compared to a simple first or last element selection as the pivot.

*/