class Solution {
public:
    int fun(int st,int en,vector<int> &dp,vector<int>& nums){
        int n=nums.size();
        if(st==0){
            dp[0]=nums[0];
            dp[1]=max(nums[0],nums[1]);
            for(int i=2;i<n-1;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
            return dp[n-2];
        }else{
            dp[1]=nums[1];
            dp[2]=max(nums[1],nums[2]);
            for(int i=3;i<n;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
            return dp[n-1];
        }
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }
        else if(n==3){
            return max(max(nums[1],nums[0]),nums[2]);
        }
        return max(fun(0,n-2,dp,nums),fun(1,n-1,dp,nums));
    }
};