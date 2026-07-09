#include<unordered_map>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max1 = 0;
        for(int num : nums)
        {
            freq[num]++;
        }
        for(auto it : freq)
        {
            if(it.second > max1 )
            {
                max1 = it.second;
            }
        }
        int ans = 0;

    for (auto it : freq)
    {
        if (it.second == max1)
        {
            ans += it.second;
        }
    }

    return ans;
   
    }
};