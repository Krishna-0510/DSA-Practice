#include<unordered_map>
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int min = 0;
        unordered_set <int> seen(nums.begin(),nums.end());
        
        int actualSum = 0;
        int expectedSum = 0;
        int missing = 0;
        int current_multiple = k;
        while(seen.count(current_multiple))
        {
            current_multiple += k;
        }
        return current_multiple;
    }
};