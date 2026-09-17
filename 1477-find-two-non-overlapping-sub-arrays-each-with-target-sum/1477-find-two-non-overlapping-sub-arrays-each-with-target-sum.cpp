#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        
        // dp[i] stores the minimum length of a valid sub-array found in arr[0...i]
        std::vector<int> dp(n, 1e9); 
        
        int min_total_length = 1e9;
        int current_sum = 0;
        int left = 0;
        int min_len_so_far = 1e9;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink the window from the left if the sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Found a valid sub-array ending at 'right' with sum == target
            if (current_sum == target) {
                int current_len = right - left + 1;

                // If there is a valid non-overlapping sub-array before 'left'
                if (left > 0 && dp[left - 1] != 1e9) {
                    min_total_length = std::min(min_total_length, current_len + dp[left - 1]);
                }

                // Update the minimum length tracked up to this point
                min_len_so_far = std::min(min_len_so_far, current_len);
            }

            // Maintain the DP array for historical minimums
            dp[right] = min_len_so_far;
        }

        return (min_total_length >= 1e9) ? -1 : min_total_length;
    }
};
