#include <unordered_map>
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for(char ch : text)
        {
            freq[ch]++;
        }
        for(auto pair : freq)
        {
            cout << pair.first << " -> " << pair.second << endl;
        }
        return min({
    freq['b'],
    freq['a'],
    freq['l'] / 2,
    freq['o'] / 2,
    freq['n']
});
    }
};