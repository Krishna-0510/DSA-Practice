#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        // k = 1
        if(k == 1)
        {
            int ans = -1;

            for(auto &p : mp)
            {
                if(p.second == 1)
                {
                    ans = max(ans, p.first);
                }
            }

            return ans;
        }

        // k = n
        if(k == n)
        {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        int ans = -1;

        if(mp[nums[0]] == 1)
        {
            ans = max(ans, nums[0]);
        }

        if(mp[nums[n - 1]] == 1)
        {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};