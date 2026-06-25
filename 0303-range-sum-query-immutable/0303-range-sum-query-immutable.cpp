class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int runningSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            prefix.push_back(runningSum);
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }

        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */