class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Base case for valid substrings starting at index 0
        max_len = 0
        
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    # Stack is empty: push current index as new baseline boundary
                    stack.append(i)
                else:
                    # Stack is not empty: calculate valid length
                    max_len = max(max_len, i - stack[-1])
                    
        return max_len
