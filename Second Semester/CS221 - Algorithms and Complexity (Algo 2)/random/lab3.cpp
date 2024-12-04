#include <iostream>
#include <vector>
using namespace std;

int knapSack(int capacity, const vector<int> &weights, const vector<int> &values, int n, vector<int> &selectedItems)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Trace back to find selected items
    int w = capacity;
    for (int i = n; i > 0 && w > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selectedItems.push_back(i - 1);
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main()
{
    vector<int> weights = {2, 3, 5, 4};
    vector<int> values = {90, 40, 30, 50};
    int capacity = 5;

    vector<int> selectedItems;
    int maxValue = knapSack(capacity, weights, values, weights.size(), selectedItems);

    cout << "Maximum value achievable: " << maxValue << endl;
    cout << "Selected items: " << endl;
    for (int i = 0; i < selectedItems.size(); ++i)
    {
        cout << weights[selectedItems[i]] << " ";
    }

    return 0;
}