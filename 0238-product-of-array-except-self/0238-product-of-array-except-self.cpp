
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size1 = nums.size();
        vector<int> left(size1);
        vector<int> right(size1);
        vector<int> result(size1);
        left[0] = 1;
        right[size1 -1] = 1;
        for(int i = 1 ; i <  size1 ;i++)
        {
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i = size1 - 2 ; i >= 0 ;i--)
        {
            right[i] = right[i+1] * nums[i + 1];
        }
        for(int i = 0 ; i < size1 ; i++)
        {
            result[i] =  left[i] * right[i];
        }
        return result;
    }
}; 