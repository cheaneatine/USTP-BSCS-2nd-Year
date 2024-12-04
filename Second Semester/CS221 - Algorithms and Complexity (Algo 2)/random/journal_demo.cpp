#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int utility;
};

// Function to solve the knapsack problem using dynamic programming
void knapsackDP(vector<Item> &items, int capacity)
{
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].utility + dp[i - 1][w - items[i - 1].weight]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Find the selected items
    int remainingCapacity = capacity;
    vector<int> selectedItems(n, 0);
    for (int i = n; i > 0 && remainingCapacity > 0; --i)
    {
        if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity])
        {
            selectedItems[i - 1] = 1;
            remainingCapacity -= items[i - 1].weight;
        }
    }

    // Display the results
    cout << "Selected items:\n";
    for (int i = 0; i < n; ++i)
    {
        if (selectedItems[i])
        {
            cout << "Item " << i + 1 << ": Weight = " << items[i].weight << ", Utility = " << items[i].utility << endl;
        }
    }
    cout << "Total utility: " << dp[n][capacity] << endl;
}

int main()
{
    vector<Item> items = {
        {3, 7}, // Foot Pack
        {4, 8}, // Bottle of water
        {6, 11} // Tent
    };
    int capacity = 10;

    knapsackDP(items, capacity);

    return 0;
}