class Solution {
public:
    string reorderSpaces(string text) {

        int spaces = 0;

        for(char ch : text)
        {
            if(ch == ' ')
                spaces++;
        }

        vector<string> words;
        string temp = "";

        for(char ch : text)
        {
            if(ch != ' ')
            {
                temp += ch;
            }
            else
            {
                if(temp != "")
                {
                    words.push_back(temp);
                    temp = "";
                }
            }
        }

        if(temp != "")
            words.push_back(temp);

        if(words.size() == 1)
        {
            return words[0] + string(spaces,' ');
        }

        int gap = spaces / (words.size()-1);
        int extra = spaces % (words.size()-1);

        string ans = "";

        for(int i = 0; i < words.size(); i++)
        {
            ans += words[i];

            if(i != words.size()-1)
            {
                ans += string(gap,' ');
            }
        }

        ans += string(extra,' ');

        return ans;
    }
};