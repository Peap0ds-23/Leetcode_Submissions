class Solution {
public:
    int fun(vector<int>& nums,vector<int>& dp,int house,int st){
        if(house<st){
            return 0;
        }
        // if(house==st+1){
        //     return nums[house];
        // }
        // if(house==st){
        //     return nums[house];
        // }

        if(dp[house]!=-1){
            return dp[house];
        }
        int right=INT_MIN;
        // if(house>0){
            right=fun(nums,dp,house-1,st);
        // }
        int left=INT_MIN;
        // if(house>1){
            left=fun(nums,dp,house-2,st)+nums[house];
        // }
        return dp[house]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }
        int case1=fun(nums,dp,n-1,1);
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        int case2=fun(nums,dp,n-2,0);
        return max(case1,case2);
    }
};