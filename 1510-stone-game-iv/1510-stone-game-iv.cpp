class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores whether the player whose turn it is can win with i stones remaining
        vector<bool> dp(n + 1, false);
        
        // Iterate through all stone counts from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Try removing every possible non-zero square number k*k
            for (int k = 1; k * k <= i; ++k) {
                // If removing k*k stones forces Bob into a losing state (dp[i - k*k] == false),
                // then Alice can win from the current state i.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // No need to check further moves for this state
                }
            }
        }
        
        return dp[n];
    }
};
