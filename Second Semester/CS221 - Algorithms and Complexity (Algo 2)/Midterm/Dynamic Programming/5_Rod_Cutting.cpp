#include <iostream>
#include <array>

using namespace std;

// Function to find the maximum revenue obtainable by cutting the rod
int maxRevenue(int n, array<int, 100> &prices)
{
    array<int, 100> dp;
    dp.fill(0);

    for (int i = 1; i <= n; ++i)
    {
        int maxVal = -1;
        for (int j = 1; j <= i; ++j)
        {
            maxVal = max(maxVal, prices[j] + dp[i - j]);
        }
        dp[i] = maxVal;
    }

    return dp[n];
}

int main()
{
    int n = 5;
    array<int, 100> prices = {1, 2, 3, 4};

    cout << "Rod length: " << n << " Prices: (";
    for (int i = 1; i <= n; ++i)
    {
        cout << prices[i];
        if (i != n)
            cout << ", ";
    }
    cout << ")" << endl;

    int revenue = maxRevenue(n, prices);

    cout << "Maximum revenue: " << revenue << " (Cut: " << n / 2 << " pieces of length " << n / 2 << ")" << endl;

    return 0;
}