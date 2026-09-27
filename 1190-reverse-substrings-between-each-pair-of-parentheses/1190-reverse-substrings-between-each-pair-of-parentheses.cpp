#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBrackets;
        vector<int> pair(n);

        // Step 1: Precompute the matching pairs for each parenthesis
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                int j = openBrackets.top();
                openBrackets.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Step 2: Traverse and build the result
        string result = "";
        int direction = 1; // 1 means moving forward, -1 means moving backward

        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];        // Teleport to the matching bracket
                direction = -direction; // Reverse the direction
            } else {
                result += s[i];     // Collect characters
            }
        }

        return result;
    }
};
