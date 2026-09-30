#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans(seq.length());
        int depth = 0;

        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                // Assign based on current depth, then increase depth
                ans[i] = depth % 2;
                depth++;
            } else {
                // Decrease depth first, then assign to match the opening parenthesis
                depth--;
                ans[i] = depth % 2;
            }
        }

        return ans;
    }
};
