#include <iostream>               // O(1) - Including a standard library header
#include <climits>                // O(1) - Including a standard library header
using namespace std;              // O(1) - Using directive for the standard namespace
int sum(int freq[], int i, int j) // O(j - i) - Function to calculate the sum of elements in the
    frequency array from index i to j
{
    int s = 0;                   // O(1) - Initializing the sum variable
    for (int k = i; k <= j; k++) // O(j - i) - Looping through the elements from index i to j
        s += freq[k];            // O(1) - Adding each element to the sum
    return s;                    // O(1) - Returning the sum
}
int optimalSearchTree(int keys[], int freq[], int n) // O(n^3) - Function to find the minimum
    cost of a binary search tree
{
    int cost[n][n];                   // O(n^2) - Declaring a 2D array to store the cost of forming binary search
    trees for (int i = 0; i < n; i++) // O(n) - Initializing the cost matrix for single key
        cost[i][i] = freq[i];         // O(1)
    for (int L = 2; L <= n; L++)      // O(n^2) - Looping through different chain lengths
    {
        for (int i = 0; i <= n - L + 1; i++) // O(n^2) - Looping through row numbers
        {
            int j = i + L - 1;                  // O(1) - Calculating the column number
            cost[i][j] = INT_MAX;               // O(1) - Initializing the cost to maximum value
            int off_set_sum = sum(freq, i, j);  // O(j - i) - Calculating the sum of frequencies from
            i to j for (int r = i; r <= j; r++) // O(n) - Looping through interval keys[i..j]
            {
                int c = ((r > i) ? cost[i][r - 1] : 0) + // O(1)
                        ((r < j) ? cost[r + 1][j] : 0) + // O(1)
                        off_set_sum;                     // O(1)
                if (c < cost[i][j])                      // O(1) - Updating the cost if necessary
                    cost[i][j] = c;                      // O(1)
            }
        }
    }
    return cost[0][n - 1]; // O(1) - Returning the minimum cost
}
int main()
{
    int keys[] = {10, 12, 20};              // O(1) - Array of keys
    int freq[] = {34, 8, 50};               // O(1) - Array of frequencies
    int n = sizeof(keys) / sizeof(keys[0]); // O(1) - Calculating the size of the keys array
    cout << "Keys: [";
    for (int i = 0; i < n; i++)
    {
        cout << keys[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "] Frequencies: [";
    for (int i = 0; i < n; i++)
    {
        cout << freq[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Optimal BST: (root: " << keys[n / 2];
    if (n > 1)
    {
        cout << ", left: (";
        for (int i = 0; i < n / 2; i++)
        {
            cout << keys[i];
            if (i != n / 2 - 1)
                cout << ", ";
        }
        cout << "), right: (";
        for (int i = n / 2 + 1; i < n; i++)
        {
            cout << keys[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << ")";
    }
    cout << ")" << endl;
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
    return 0;
    // O(n) - Printing the keys and frequencies arrays
    // O(n) - Printing the root, left, and right subtrees
    // O(n^3) - Calling optimalSearchTree function
    // O(1) - Printing the minimum cost of the optimal BST
    // O(1) - Returning 0 to indicate successful completion
}