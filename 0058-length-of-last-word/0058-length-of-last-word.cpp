class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count last word length
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};