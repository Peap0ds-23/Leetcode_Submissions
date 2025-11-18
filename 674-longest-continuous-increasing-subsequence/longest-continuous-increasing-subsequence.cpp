class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=1,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                count++;
                len=max(len,count);
            }else{
                count=1;
            }
        }return len;
    }
};