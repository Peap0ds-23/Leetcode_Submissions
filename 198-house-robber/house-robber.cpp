class Solution {
public:
    int money(vector<int>& nums,vector<int>& dp,int n){
        if(n==0 ){
            return nums[n];
        }
        if(n==1){
            return max(nums[0],nums[1]);
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int count=0;
        int left=money(nums,dp,n-1);
        int right=money(nums,dp,n-2)+nums[n];
        return dp[n]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n==1){
            return nums[0];
        }
        return money(nums,dp,n-1);
    }

};