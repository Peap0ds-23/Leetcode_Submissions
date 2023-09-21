class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=n-2;i>=0;i--){
            sum+=1;
            if(nums[i]>=sum){
                sum=0;
            }
        }
        // if(sum==0){
        //     return true;
        // }return false;
        return sum==0;
    }
};