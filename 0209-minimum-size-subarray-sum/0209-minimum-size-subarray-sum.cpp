class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currSum = 0;
        int  left = 0;
        int minNum = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            currSum += nums[i];
            while(currSum >= target)
            {
                mini = min(mini,i - left + 1);
                currSum -= nums[left];
                left++;
            }
        }  
      return (mini == INT_MAX) ? 0 :mini;
    }
};