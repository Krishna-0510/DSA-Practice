#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, there is no matching opening bracket
                if (st.empty()) return false;
                
                // Check if the top of the stack matches the closing bracket
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                
                // Pop the matched opening bracket
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets were correctly matched
        return st.empty();
    }
};
