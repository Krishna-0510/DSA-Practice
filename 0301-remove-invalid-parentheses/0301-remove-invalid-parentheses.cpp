#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool foundMinimumRemovals = false;

        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();

                // If a valid string is found, add it to the result
                if (isValid(curr)) {
                    result.push_back(curr);
                    foundMinimumRemovals = true;
                }

                // If we already found valid strings at this level, 
                // skip generating further child states (next level)
                if (foundMinimumRemovals) continue;

                // Generate all possible states by removing one parenthesis
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue; // Skip alphabets

                    string nextState = curr.substr(0, j) + curr.substr(j + 1);
                    
                    if (visited.find(nextState) == visited.end()) {
                        visited.insert(nextState);
                        q.push(nextState);
                    }
                }
            }

            // Stop BFS since any valid answers found at this level are of minimum removals
            if (foundMinimumRemovals) break;
        }

        return result;
    }
};
