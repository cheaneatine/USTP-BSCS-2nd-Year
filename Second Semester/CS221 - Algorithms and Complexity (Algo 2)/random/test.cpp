#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(int capacity, const std::vector<int> &weights, const std::vector<int> &values, std::vector<std::vector<int>> &dp)
{
    int n = weights.size();

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

void printChosenItems(int capacity, const std::vector<int> &weights, const std::vector<int> &values, const std::vector<std::vector<int>> &dp)
{
    int n = weights.size();
    int maxValue = dp[n][capacity];
    int remainingCapacity = capacity;
    std::vector<int> chosenItems;

    for (int i = n; i > 0 && maxValue > 0; --i)
    {
        if (maxValue != dp[i - 1][remainingCapacity])
        {
            chosenItems.push_back(i);
            maxValue -= values[i - 1];
            remainingCapacity -= weights[i - 1];
        }
    }

    auto minIter = std::min_element(values.begin(), values.end());
    auto maxIter = std::max_element(values.begin(), values.end());
    int minIndex = std::distance(values.begin(), minIter) + 1;
    int maxIndex = std::distance(values.begin(), maxIter) + 1;

    std::cout << "Chosen items: " << minIndex << " and " << maxIndex << std::endl;
}

int main()
{
    std::vector<int> weights = {2, 3, 1, 4};
    std::vector<int> values = {10, 40, 30, 50};
    int capacity = 5;

    std::vector<std::vector<int>> dp(weights.size() + 1, std::vector<int>(capacity + 1, 0));
    int max_value = knapsack(capacity, weights, values, dp);

    std::cout << "Maximum value achievable: " << max_value << std::endl;
    printChosenItems(capacity, weights, values, dp);

    return 0;
}