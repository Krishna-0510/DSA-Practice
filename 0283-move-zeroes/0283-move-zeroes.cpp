class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int temp;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != 0)
            {
                temp = nums[i];
                nums[i] = nums[start];
                nums[start] = temp;
                start++;
            }
        }

    }
};