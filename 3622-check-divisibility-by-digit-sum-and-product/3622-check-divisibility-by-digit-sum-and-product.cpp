class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digit_sum = 0;
        int digit_product = 1;
        
        // Extract each digit and calculate sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digit_sum += digit;
            digit_product *= digit;
            temp /= 10;
        }
        
        int total_divisor = digit_sum + digit_product;
        
        // Check for division by zero just in case, then check divisibility
        if (total_divisor == 0) {
            return false; 
        }
        
        return (n % total_divisor == 0);
    }
};
