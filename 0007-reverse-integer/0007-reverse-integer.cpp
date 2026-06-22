#include<climits>
class Solution {
public:
    int reverse(int x) {
       int rev = 0;
       while(x != 0 )
        {
            int last_digit = x % 10;
            
            if(
                rev > INT_MAX / 10 ||
                (rev == INT_MAX / 10 && last_digit > 7) ||
                rev < INT_MIN / 10 ||
                (rev == INT_MIN / 10 && last_digit < -8)
            )   
            {
                return 0;
            }
            rev = rev * 10 + last_digit;
            x = x / 10;
        }
        return rev;
    }
};