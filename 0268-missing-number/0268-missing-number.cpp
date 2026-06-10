
#include<unordered_set>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int expectedSum = n*(n+1) / 2;
        // int actualSum = 0;
        // for(int i = 0 ; i < nums.size() ; i++)
        // {
        //     actualSum += nums[i];
        // }
        // return expectedSum-actualSum;
        

        //USING HASH SET
        unordered_set<int> st;
        for(int num : nums)
        {
            st.insert(num);
        }
        for(int i = 0 ; i <= nums.size(); i++)
        {
            if(st.find(i) == st.end())
            {
                return i;
            }
        }
        return -1;
    }
};