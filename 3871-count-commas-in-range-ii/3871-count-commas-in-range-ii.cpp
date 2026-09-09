class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long threshold = 1000; // Starts at 1,000 for the 1st comma
        
        while (n >= threshold) {
            total_commas += (n - threshold + 1);
            
            // Prevent potential overflow before multiplying by 1000
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
            threshold *= 1000;
        }
        
        return total_commas;
    }
};
