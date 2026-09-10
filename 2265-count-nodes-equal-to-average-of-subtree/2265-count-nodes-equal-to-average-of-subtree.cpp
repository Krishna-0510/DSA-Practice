class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int matchingNodesCount = 0;
        calculateSubtreeDetails(root, matchingNodesCount);
        return matchingNodesCount;
    }

private:
    // Helper function returns {subtree_sum, subtree_count}
    pair<int, int> calculateSubtreeDetails(TreeNode* node, int& matchingNodesCount) {
        if (!node) {
            return {0, 0};
        }
        
        // Post-order traversal: visit children first
        auto [leftSum, leftCount] = calculateSubtreeDetails(node->left, matchingNodesCount);
        auto [rightSum, rightCount] = calculateSubtreeDetails(node->right, matchingNodesCount);
        
        // Compute total sum and count for the current subtree
        int currentSubtreeSum = leftSum + rightSum + node->val;
        int currentSubtreeCount = leftCount + rightCount + 1;
        
        // LeetCode definition: average rounded down to the nearest integer
        int calculatedAverage = currentSubtreeSum / currentSubtreeCount;
        
        // Check if the current node meets the condition
        if (node->val == calculatedAverage) {
            matchingNodesCount++;
        }
        
        return {currentSubtreeSum, currentSubtreeCount};
    }
};
