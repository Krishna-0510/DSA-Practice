#include <string>
#include <algorithm>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        int left = 0;
        int count_ones = 0;
        std::string ans = "";

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count_ones++;
            }

            // Shrink window from the left while maintaining exactly k ones
            while (count_ones == k) {
                std::string current_sub = s.substr(left, right - left + 1);
                
                // If it's the first valid substring or shorter than the previous best
                if (ans.empty() || current_sub.length() < ans.length()) {
                    ans = current_sub;
                } 
                // If it has the same length, pick the lexicographically smaller one
                else if (current_sub.length() == ans.length()) {
                    ans = std::min(ans, current_sub);
                }

                // Move left pointer to look for smaller/better substrings
                if (s[left] == '1') {
                    count_ones--;
                }
                left++;
            }
        }

        return ans;
    }
};
