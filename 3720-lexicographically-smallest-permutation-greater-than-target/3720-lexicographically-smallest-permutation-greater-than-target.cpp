#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Try to find the first position 'i' from the right where we can 
        // branch off to a character strictly greater than target[i].
        for (int i = n - 1; i >= 0; i--) {
            // Step 1: Check if the prefix target[0 ... i-1] can be formed
            vector<int> current_counts = counts;
            bool valid_prefix = true;
            
            for (int j = 0; j < i; j++) {
                int idx = target[j] - 'a';
                if (current_counts[idx] > 0) {
                    current_counts[idx]--;
                } else {
                    valid_prefix = false;
                    break;
                }
            }

            if (!valid_prefix) continue;

            // Step 2: Look for a character greater than target[i]
            int target_char_idx = target[i] - 'a';
            int choice = -1;
            for (int c = target_char_idx + 1; c < 26; c++) {
                if (current_counts[c] > 0) {
                    choice = c;
                    break; // Take the smallest character strictly greater
                }
            }

            // Step 3: If a valid choice is found, construct the final result
            if (choice != -1) {
                string result = target.substr(0, i);
                result += (char)('a' + choice);
                current_counts[choice]--;

                // Append the remaining characters in ascending order
                for (int c = 0; c < 26; c++) {
                    while (current_counts[c] > 0) {
                        result += (char)('a' + c);
                        current_counts[c]--;
                    }
                }
                return result;
            }
        }

        return ""; // Return empty string if no valid permutation exists
    }
};
