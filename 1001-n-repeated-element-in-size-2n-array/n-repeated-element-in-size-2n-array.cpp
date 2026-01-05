class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        if(nums[0]==nums[n-1] || nums[0]==nums[n-2]){
            return nums[0];
        }
        if(nums[1]==nums[n-1] || nums[1]==nums[n-2]){
            return nums[1];
        }
        return -1;
    }
};