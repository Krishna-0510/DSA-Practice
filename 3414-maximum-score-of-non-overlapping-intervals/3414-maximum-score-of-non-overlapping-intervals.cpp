#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int l, r, weight, id;
    
    // Sort primarily by start time to look forward for non-overlapping intervals
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r < other.r;
        return weight > other.weight;
    }
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(arr.begin(), arr.end());
        
        // To quickly find the next non-overlapping interval
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = arr[i].l;
        }
        
        // dp_weight[i][j]: max weight from suffix i using at most j intervals
        vector<vector<long long>> dp_weight(n + 1, vector<long long>(5, 0));
        // dp_ans[i][j]: stores the sorted list of original indices for that optimal state
        vector<vector<vector<int>>> dp_ans(n + 1, vector<vector<int>>(5));
        
        // Fill DP from back to front
        for (int i = n - 1; i >= 0; --i) {
            // Find the first interval that starts strictly after the current one ends
            int next_idx = upper_bound(starts.begin(), starts.end(), arr[i].r) - starts.begin();
            
            for (int j = 1; j <= 4; ++j) {
                // Option 1: Skip the current interval
                long long w_skip = dp_weight[i + 1][j];
                vector<int> ans_skip = dp_ans[i + 1][j];
                
                // Option 2: Take the current interval
                long long w_take = arr[i].weight + dp_weight[next_idx][j - 1];
                vector<int> ans_take = {arr[i].id};
                ans_take.insert(ans_take.end(), dp_ans[next_idx][j - 1].begin(), dp_ans[next_idx][j - 1].end());
                sort(ans_take.begin(), ans_take.end()); // Keep list of indices sorted
                
                // Choose the option with higher weight
                if (w_take > w_skip) {
                    dp_weight[i][j] = w_take;
                    dp_ans[i][j] = ans_take;
                } else if (w_skip > w_take) {
                    dp_weight[i][j] = w_skip;
                    dp_ans[i][j] = ans_skip;
                } else {
                    // Tie-breaker: choose the lexicographically smaller index list
                    dp_weight[i][j] = w_take;
                    if (ans_take < ans_skip) {
                        dp_ans[i][j] = ans_take;
                    } else {
                        dp_ans[i][j] = ans_skip;
                    }
                }
            }
        }
        
        return dp_ans[0][4];
    }
};
