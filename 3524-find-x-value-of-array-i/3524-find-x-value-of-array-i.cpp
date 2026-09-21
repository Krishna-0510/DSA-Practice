#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int current_mod = num % k;

            // Option 1: Start a new subarray consisting solely of nums[i]
            next_dp[current_mod]++;

            // Option 2: Extend existing subarrays ending at the previous element
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_mod = (r * current_mod) % k;
                    next_dp[next_mod] += dp[r];
                }
            }

            // Accumulate counts for subarrays ending at the current element
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            // Transition to the next element
            dp = std::move(next_dp);
        }

        return ans;
    }
};