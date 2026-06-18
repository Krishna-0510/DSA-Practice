class Solution {
public:
    int findMin(vector<int>& nums) {
        // BRUTE FORCE : 
        // int start = nums[0];
        // int temp = 0 ;
        // for(int i = 0 ; i < nums.size() - 1; i++)
        // {
           
        //     if(nums[i+1] < nums[i])
        //     {
        //         //temp = nums[i+1];
        //         return nums[i+1];   
        //     }
        // }
        // return nums[0];

        // OPTIMAL : 
        int low = 0;
        int high = nums.size() - 1;
       
        while(low < high)
        {
             int mid = low + (high - low) / 2;
            if(nums[mid] < nums[high])
            {
                high = mid;
            }
            else if(nums[mid] > nums[high])
            {
               low = mid + 1;
            }
        }
        return nums[low];
    } 
};