class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i = 0;
            int j = nums.size() - 1;
            
        sort(nums.begin(), nums.end());
        int closetSum = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < nums.size() - 2; i++)
        {
             if(i > 0 && nums[i] == nums[i - 1]){
                    continue;
                }
            int left = i + 1;
            int right = nums.size() - 1;
            while( left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
               
                if(abs(sum - target) < abs(closetSum - target) )    
                {
                    closetSum = sum;
                }
                
                else if(sum < target)
                {
                    left++;
                }
                else if(sum > target)
                {
                    right--;
                }
                else
                {
                    return sum;
                }
            }
        }
        return closetSum;
    }
};