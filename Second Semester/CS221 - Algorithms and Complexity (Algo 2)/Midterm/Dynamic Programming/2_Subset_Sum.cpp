#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(const vector<int> &nums, int target)
{
    int n = nums.size();
    // dp[i][j] indicates whether there is a subset of nums[0...i-1] that adds up to j
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // An empty subset can always achieve a sum of 0
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            if (j < nums[i - 1])
            {
                // If the current number is greater than the target, we cannot include it
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // We can either include the current number or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    vector<int> nums = {3, 2, 7};
    int target = 5;

    cout << "Set: [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "] Target sum: " << target << endl;

    if (subsetSum(nums, target))
    {
        cout << "Result: True (Subset: [";
        bool first = true;
        for (int num : nums)
        {
            if (target >= num && subsetSum(nums, target - num))
            {
                if (!first)
                    cout << ", ";
                cout << num;
                target -= num;
                first = false;
            }
        }
        cout << "])" << endl;
    }
    else
    {
        cout << "Result: False" << endl;
    }

    return 0;
}