#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Segment Tree node representation
struct Node {
    int mx;      // Length of the longest uniform substring in this range
    int pref;    // Length of the uniform prefix
    int suff;    // Length of the uniform suffix
    char lc;     // Leftmost character of this range
    char rc;     // Rightmost character of this range
};

class Solution {
private:
    vector<Node> tree;
    string str;

    // Combine left and right child nodes into a parent node
    Node merge(const Node& left, const Node& right, int lenL, int lenR) {
        Node parent;
        parent.lc = left.lc;
        parent.rc = right.rc;
        
        // Default values before checking crossing boundaries
        parent.pref = left.pref;
        parent.suff = right.suff;
        parent.mx = max(left.mx, right.mx);

        // Check if characters at the boundary merge point match
        if (left.rc == right.lc) {
            parent.mx = max(parent.mx, left.suff + right.pref);
            
            // If the entire left segment is uniform, the prefix extends into the right segment
            if (left.pref == lenL) {
                parent.pref = left.pref + right.pref;
            }
            // If the entire right segment is uniform, the suffix extends into the left segment
            if (right.suff == lenR) {
                parent.suff = right.suff + left.suff;
            }
        }
        return parent;
    }

    // Build the Segment Tree
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, str[start], str[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    // Point update: Modify a character at a specific index
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);
        
        // Construct the initial tree structure
        build(1, 0, n - 1);
        
        int k = queryIndices.size();
        vector<int> lengths(k);
        
        // Execute updates sequentially and extract the global maximum length
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            lengths[i] = tree[1].mx;
        }
        
        return lengths;
    }
};
