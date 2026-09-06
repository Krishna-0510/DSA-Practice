class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[j] stores the number of distinct subsequences of s that equal t[0...j-1]
        // Using unsigned long long to prevent overflow during intermediate additions
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty string t is a subsequence of any prefix of s exactly 1 time
        dp[0] = 1;
        
        // Iterate through string s
        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through string t to use values from the previous iteration of s
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If they don't match, dp[j] remains dp[j] (inherits old value)
            }
        }
        
        return dp[n];
    }
};
