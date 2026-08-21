#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate Greatest Common Divisor
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Helper function to calculate Least Common Multiple
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // Counts how many valid amounts exist <= M using Inclusion-Exclusion
    long long countAmounts(long long M, const std::vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        int totalSubsets = 1 << n;

        // Iterate through all possible subsets (excluding the empty subset)
        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int bitsCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bitsCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    // Break early if LCM exceeds M to avoid overflow
                    if (currentLcm > M) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bitsCount % 2 == 1) {
                count += M / currentLcm;
            } else {
                count -= M / currentLcm;
            }
        }
        return count;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        long long low = *std::min_element(coins.begin(), coins.end());
        long long high = low * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;        // Potential answer found, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;    // Not enough amounts, try larger
            }
        }
        return ans;
    }
};
