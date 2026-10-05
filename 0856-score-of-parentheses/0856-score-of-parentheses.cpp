#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        std::vector<int> stack = {0}; // Base layer score starts at 0
        
        for (char c : s) {
            if (c == '(') {
                stack.push_back(0); // Enter a deeper nesting level
            } else {
                int v = stack.back();
                stack.pop_back(); // Complete inner level
                
                // () contributes 1, otherwise (A) contributes 2 * A
                stack.back() += std::max(2 * v, 1);
            }
        }
        
        return stack.back();
    }
};
