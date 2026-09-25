#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> unique_words = parse(expression, i);
        return vector<string>(unique_words.begin(), unique_words.end());
    }

private:
    set<string> parse(const string& exp, int& i) {
        vector<set<string>> groups; // Stores sets separated by commas at this level
        set<string> current = {""}; // Tracks consecutive elements being concatenated

        while (i < exp.length()) {
            if (exp[i] == '{') {
                i++; // Skip '{'
                set<string> inner = parse(exp, i);
                current = combine(current, inner);
            } else if (exp[i] == '}') {
                i++; // Skip '}'
                break; // Return back to the outer level
            } else if (exp[i] == ',') {
                i++; // Skip ','
                groups.push_back(current);
                current = {""}; // Reset for the next term in union
            } else {
                // Parse consecutive lowercase letters
                string atom = "";
                while (i < exp.length() && islower(exp[i])) {
                    atom += exp[i];
                    i++;
                }
                current = combine(current, {atom});
            }
        }
        groups.push_back(current);

        // Perform Union operation across all accumulated comma-separated groups
        set<string> result;
        for (const auto& g : groups) {
            result.insert(g.begin(), g.end());
        }
        return result;
    }

    // Helper function to perform the Cartesian product (concatenation) of two sets
    set<string> combine(const set<string>& s1, const set<string>& s2) {
        set<string> res;
        for (const string& str1 : s1) {
            for (const string& str2 : s2) {
                res.insert(str1 + str2);
            }
        }
        return res;
    }
};
