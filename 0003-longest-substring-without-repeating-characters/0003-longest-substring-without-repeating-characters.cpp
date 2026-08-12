#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Tracks the index position + 1 of each character (covers all ASCII characters)
        std::vector<int> charIndex(128, 0);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        // Expand the sliding window with the right pointer
        for (int right = 0; right < s.length(); ++right) {
            // If the character was seen inside the current window, move left boundary
            if (charIndex[s[right]] > left) {
                left = charIndex[s[right]];
            }
            
            // Record the current character's 1-indexed position
            charIndex[s[right]] = right + 1;
            
            // Update maximum length
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
