#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the optimal binary search tree structure
void optimalBST(vector<char> keys, vector<int> freq)
{
    int n = keys.size();
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0)); // DP table for storing costs
    vector<vector<int>> root(n, vector<int>(n, 0));         // DP table for storing roots of optimal subtrees

    // Initializing cost table with frequencies
    for (int i = 0; i < n; ++i)
        cost[i][i] = freq[i];

    // Constructing cost table
    for (int L = 2; L <= n; ++L)
    {
        for (int i = 0; i <= n - L + 1; ++i)
        {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; ++r)
            {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        ((r >= i && r <= j) ? freq[r] : 0);

                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Constructing optimal binary search tree
    cout << "Optimal BST: ";
    cout << "(root: " << keys[root[0][n - 1]];
    constructOptimalBST(keys, root, 0, n - 1);
    cout << ")" << endl;
}

// Recursive function to construct optimal BST structure
void constructOptimalBST(vector<char> &keys, vector<vector<int>> &root, int i, int j)
{
    if (i == j)
        return;

    int r = root[i][j];

    if (i <= r - 1)
    {
        cout << ", left: " << keys[root[i][r - 1]];
        constructOptimalBST(keys, root, i, r - 1);
    }

    if (r + 1 <= j)
    {
        cout << ", right: " << keys[root[r + 1][j]];
        constructOptimalBST(keys, root, r + 1, j);
    }
}

int main()
{
    vector<char> keys = {'A', 'B', 'C', 'D'};
    vector<int> freq = {2, 3, 1, 4};
    optimalBST(keys, freq);
    return 0;
}