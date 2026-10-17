#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // Structure to hold element value, its digit sum, and its initial index
    struct Element {
        int val;
        int digit_sum;
        int orig_idx;
    };

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Element> sorted_nums(n);

        // 1. Initialize the array with value, digit sum, and original index
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], getDigitSum(nums[i]), i};
        }

        // 2. Sort based on the custom criteria
        sort(sorted_nums.begin(), sorted_nums.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum; // Primary: ascending digit sum
            }
            return a.val < b.val;                 // Secondary: ascending value
        });

        // 3. Find the minimum number of swaps using graph cycle decomposition
        int total_swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            // Skip if already visited or if the element is already in the correct position
            if (visited[i] || sorted_nums[i].orig_idx == i) {
                continue;
            }

            int cycle_size = 0;
            int curr = i;

            // Traverse the cycle
            while (!visited[curr]) {
                visited[curr] = true;
                curr = sorted_nums[curr].orig_idx;
                cycle_size++;
            }

            // A cycle of size 'k' requires 'k - 1' swaps
            if (cycle_size > 1) {
                total_swaps += (cycle_size - 1);
            }
        }

        return total_swaps;
    }
};
