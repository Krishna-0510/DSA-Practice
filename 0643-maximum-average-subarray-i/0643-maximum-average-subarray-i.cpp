class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxi = 0;
        int curr_sum = 0;
        for(int i = 0 ; i < k ; i++)
        {
            curr_sum += nums[i];
        }
        maxi = curr_sum;
        for(int i = k ; i < nums.size() ; i++)
        {
            curr_sum = nums[i] + curr_sum - nums[i-k];
            if(curr_sum > maxi)
            {
                maxi = curr_sum;
            }   
        }
        return (double)maxi / k;
    }
};