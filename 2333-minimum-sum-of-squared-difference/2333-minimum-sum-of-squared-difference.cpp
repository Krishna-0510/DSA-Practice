#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        // Find the maximum possible difference to size the bucket array dynamically
        int max_diff = 0;
        std::vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = std::abs(nums1[i] - nums2[i]);
            max_diff = std::max(max_diff, diff[i]);
        }
        
        // If the total operations 'k' can wipe out all differences, return 0
        long long total_diff_sum = 0;
        for (int d : diff) total_diff_sum += d;
        if (total_diff_sum <= k) return 0;
        
        // Bucket array to store frequencies of each difference
        std::vector<int> bucket(max_diff + 1, 0);
        for (int d : diff) {
            bucket[d]++;
        }
        
        // Greedily reduce the largest differences down to smaller ones
        for (int i = max_diff; i > 0; --i) {
            if (bucket[i] > 0) {
                // If we have enough k to decrement all elements of value 'i'
                if (k >= bucket[i]) {
                    k -= bucket[i];
                    bucket[i - 1] += bucket[i];
                    bucket[i] = 0;
                } else {
                    // If we can only decrement 'k' elements of value 'i'
                    bucket[i - 1] += k;
                    bucket[i] -= k;
                    k = 0;
                    break; // No more operations left
                }
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        for (long long i = 1; i <= max_diff; ++i) {
            if (bucket[i] > 0) {
                ans += bucket[i] * (i * i);
            }
        }
        
        return ans;
    }
};
