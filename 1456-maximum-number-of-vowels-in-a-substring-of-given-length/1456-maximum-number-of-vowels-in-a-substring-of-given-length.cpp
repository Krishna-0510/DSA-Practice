class Solution {
public:
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0 ; i < k ; i++)
        {   
            if(isVowel(s[i]))
            {
                count++;
            }
        }
        int maxCount = count;
        int maxSum = max(maxCount,count);
        for(int i = k ; i < s.length(); i++)
        {
            if(isVowel(s[i-k]))
            {
                count--;
            }
            if (isVowel(s[i])) {
                count++;
            }
            maxSum = max(maxSum , count);
        }
        return maxSum;
    }
    
};