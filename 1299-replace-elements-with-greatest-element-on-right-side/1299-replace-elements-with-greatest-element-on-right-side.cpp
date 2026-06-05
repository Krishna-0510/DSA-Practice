class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int end = arr.size() - 1;
        int index = 0;
        int maxRight = -1;
        for(int i = end ; i >= 0 ; i--)
        {
            int currNum = arr[i];
            arr[i] = maxRight;
            maxRight = max(maxRight , currNum);

        }
        return arr;
    }
};