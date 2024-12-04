#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Insertion Sort for integers
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

int main()
{
    // Seed for random number generation
    srand(time(0));

    // Generate a large vector with random integers
    int size = 1000; // Adjust the size as needed
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

    int comparisons_insertion = insertionSort(arr);

    cout << "\nSorted array using Insertion Sort:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}