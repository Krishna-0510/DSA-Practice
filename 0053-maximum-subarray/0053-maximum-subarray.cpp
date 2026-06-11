#include<climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum = INT_MIN;

       for(int i = 0 ; i < nums.size() ;i++)
       {

            int currSum = max(nums[i], currSum + nums[i]);
            if(currSum > maxSum)
            {
                maxSum = currSum;
            }
       }
       return maxSum;
    } 
};