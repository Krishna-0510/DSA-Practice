#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> bitCount(32, 0);
        
        // Step 1: Count the total occurrences of each bit position
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSumOfSquares = 0;
        
        // Step 2: Form the k largest possible elements greedily
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i < 32; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--; // Use up one '1' at this position
                }
            }
            // Step 3: Add the square of the formed number to the total
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSumOfSquares;
    }
};
