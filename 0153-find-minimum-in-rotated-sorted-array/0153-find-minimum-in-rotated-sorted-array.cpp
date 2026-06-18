class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = nums[0];
        int temp = 0 ;
        for(int i = 0 ; i < nums.size() - 1; i++)
        {
           
            if(nums[i+1] < nums[i])
            {
                //temp = nums[i+1];
                return nums[i+1];   
            }
        }
        return nums[0];
    }
};