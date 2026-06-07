class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        vector<int> temp;
        int index = 0;
        for(int i = 0 ; i < end ; i++)
        {
            if(nums[i] != 0)
            {
                temp.push_back(nums[i]);
                
            }
            else
            {
               index++;
            }
        }
        for(int i = 0 ; i < index; i++)
        {   
            temp.push_back(0);
            nums = temp;
        }
        // return nums;
    }
};