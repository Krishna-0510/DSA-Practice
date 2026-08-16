class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count frequencies of remainders modulo 3
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int stone : stones) {
            int rem = stone % 3;
            if (rem == 0) cnt0++;
            else if (rem == 1) cnt1++;
            else cnt2++;
        }
        
        // Case 1: Even number of 0-stones
        if (cnt0 % 2 == 0) {
            // Alice wins if both types of stones exist
            return min(cnt1, cnt2) >= 1;
        }
        
        // Case 2: Odd number of 0-stones
        // Alice wins if the absolute difference is strictly greater than 2
        return abs(cnt1 - cnt2) > 2;
    }
};
