class Solution {
public:
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums,k) - slidingWindowAtMost(nums,k-1);
    }
    int slidingWindowAtMost(vector<int>& nums, int distinctK) {
        int left = 0, totalCount = 0,count=0;
        for (int right = 0; right < nums.size(); right++) {
            if(nums[right]&1){
                count++;
            }
            while (count > distinctK) {
                if(nums[left]&1){
                    count--;
                }
                left++;
            }
            totalCount += (right - left + 1);
        }
        return totalCount;
    }
};