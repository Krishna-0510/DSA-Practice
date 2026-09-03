class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int currSum = 0;
        int maxi = 0;
        int count = 0;
        for(int i = 0 ; i < k ; i++)
        {
            currSum += arr[i];
        }
         if(currSum >=  k * threshold)
            {
                count++;
            }
        for(int i = k ; i < arr.size(); i++)
        {
            currSum = currSum + arr[i] - arr[i-k];
            if(currSum >=  k * threshold)
            {
                count++;
            }
        }
        return count;
    }
    
};