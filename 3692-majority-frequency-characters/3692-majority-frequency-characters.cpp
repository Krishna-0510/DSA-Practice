#include<unordered_map>
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(char ch : s)
        {
            freq[ch]++;
        }
        unordered_map<int, string> groups;
        for (auto it : freq) {
            groups[it.second] += it.first;
        }
        int maxGroupSize = 0;
        int bestFrequency = 0;
        string ans = "";

        for (auto it : groups) {
            int frequency = it.first;
            string chars = it.second;

            if (chars.size() > maxGroupSize ||
               (chars.size() == maxGroupSize && frequency > bestFrequency)) {

                maxGroupSize = chars.size();
                bestFrequency = frequency;
                ans = chars;
            }
        }

        return ans;
    }
};