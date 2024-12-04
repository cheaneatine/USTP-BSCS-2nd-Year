#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(const string &X, const string &Y)
{
    int m = X.size();
    int n = Y.size();

    // dp[i][j] represents the length of LCS of X[0...i-1] and Y[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table using dynamic programming
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n]; // Length of LCS
}

string findLCS(const string &X, const string &Y)
{
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table using dynamic programming
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS from the dp table
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}

int main()
{
    string X = "AGTGAT";
    string Y = "TGATCA";

    cout << "Sequences: X = \"" << X << "\" Y = \"" << Y << "\"" << endl;

    int lcsLength = longestCommonSubsequence(X, Y);
    cout << "Length of LCS: " << lcsLength;

    string lcs = findLCS(X, Y);
    cout << " (LCS: \"" << lcs << "\")" << endl;

    return 0;
}