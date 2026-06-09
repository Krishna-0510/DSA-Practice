class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        if(s.size() != t.size())
        {
            return false;
        }
        //Counting frequency of characters
        for(char ch : s)
        {
            freq[ch - 'a']++;
        }
        for(char ch : t)
        {
            freq[ch - 'a']--;
        }
        for(int count : freq)
        {
            if(count != 0)
            {
                return false;
            }
            
        }
        return true;
    }
};