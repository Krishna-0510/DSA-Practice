class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Include the current element in the window
            freq[nums[right]]++;
            
            // Shrink the window from the left until the condition holds true
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            // Update the maximum length of a valid subarray
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
