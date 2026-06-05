class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string word = "";

        for(char ch : s) {

            if(ch != ' ') {
                word += ch;
            }
            else {
                if(!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        if(!word.empty()) {
            words.push_back(word);
        }

        string ans = "";

        for(int i = words.size() - 1; i >= 0; i--) {

            ans += words[i];

            if(i != 0) {
                ans += " ";
            }
        }

        return ans;
    }
};