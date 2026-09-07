class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        // last[c] stores the number of subsequences added by character 'c' 
        // during its last occurrence.
        vector<long long> last(26, 0); 
        long long total = 0; // Tracks total distinct subsequences

        for (char c : s) {
            int idx = c - 'a';
            // Subsequences added by the current character
            long long new_added = (total + 1) % MOD; 
            
            // Current total becomes: old_total + new_added - what this char added previously
            long long next_total = (total + new_added - last[idx] + MOD) % MOD;
            
            // Update the record for this character and the global total
            last[idx] = new_added;
            total = next_total;
        }
        
        return total;
    }
};
