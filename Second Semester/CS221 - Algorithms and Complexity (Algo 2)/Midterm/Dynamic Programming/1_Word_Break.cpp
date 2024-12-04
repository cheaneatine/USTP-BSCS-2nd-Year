#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(const string &s, const unordered_set<string> &wordDict)
{
    int n = s.size();
    // dp[i] indicates whether substring s[0...i-1] can be segmented into words in the dictionary
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string can be segmented

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // Check if substring s[j...i-1] is in the dictionary and s[0...j-1] can be segmented
            if (dp[j] && wordDict.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break; // No need to check further
            }
        }
    }

    return dp[n];
}

int main()
{
    unordered_set<string> wordDict = {"apple", "pear", "pie"};
    string s = "applepie";

    cout << "Dictionary: [";
    for (const auto &word : wordDict)
    {
        cout << "\"" << word << "\", ";
    }
    cout << "]" << endl;

    cout << "String: \"" << s << "\"" << endl;

    if (wordBreak(s, wordDict))
    {
        cout << "Result: True (\"apple pie\")" << endl;
    }
    else
    {
        cout << "Result: False" << endl;
    }

    return 0;
}