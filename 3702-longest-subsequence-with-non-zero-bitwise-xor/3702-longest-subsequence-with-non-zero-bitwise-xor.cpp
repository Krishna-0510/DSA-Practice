#include <vector>
#include <numeric>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // If the total XOR sum is already non-zero, take the whole array
        if (totalXor != 0) {
            return nums.size();
        }
        
        // If total XOR is 0 but we have at least one non-zero element, 
        // removing that single non-zero element leaves a non-zero XOR sum.
        if (hasNonZero) {
            return nums.size() - 1;
        }
        
        // If all elements are 0, no non-zero XOR subsequence can be formed
        return 0;
    }
};
