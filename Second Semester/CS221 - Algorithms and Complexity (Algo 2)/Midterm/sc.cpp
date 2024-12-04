#include <bits/stdc++.h>                                         // O(1) - Including a standard library header
using namespace std;                                             // O(1) - Using directive for the standard namespace
int lcs(char *X, char *Y, int m, int n, vector<vector<int>> &dp) // O(m*n) - Function to find the length of the Longest Common Subsequence(LCS)
{
    if (m == 0 || n == 0) // O(1) - Base case: if either of the strings is empty, LCS is 0
        return 0;
    if (X[m - 1] == Y[n - 1])                              // O(1) - If the last characters of both strings match
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp); // O(1) + Recursive call
    if (dp[m][n] != -1)
    {                    // O(1) - If the value is already computed
        return dp[m][n]; // O(1) - Return the stored value
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),  // O(1) + Recursive call
                          lcs(X, Y, m - 1, n, dp)); // O(1) + Recursive call
}
int main()
{
    char X[] = "AGGTAB";                                   // O(1) - Initializing string X
    char Y[] = "GXTXAYB";                                  // O(1) - Initializing string Y
    int m = strlen(X);                                     // O(m) - Calculating the length of string X
    int n = strlen(Y);                                     // O(n) - Calculating the length of string Y
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // O(m*n) - Initializing a 2D vector for memoization
    cout << "Length of LCS is " << lcs(X, Y, m, n, dp);    // O(m*n) - Calling the lcs function and printing the length of LCS return 0;   // O(1) - Returning 0 to indicate successful completion
}