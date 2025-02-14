class Solution {
public:
    int fun(vector<int> &dp,vector<int> &nums,int st,int en){
        dp[st]=nums[st-1];
        dp[st+1]=max(nums[st],nums[st-1]);
        for(int i=st+2;i<=en;i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[en];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n+1,0);
        return max(fun(dp,nums,2,n),fun(dp,nums,1,n-1));
    }
};