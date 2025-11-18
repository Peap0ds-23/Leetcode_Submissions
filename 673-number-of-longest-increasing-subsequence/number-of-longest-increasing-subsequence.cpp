class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int maxx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int a=nums[i];
                int b=nums[j];
                if(b<a && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }else if(b<a && dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxx=max(maxx,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxx){
                ans+=count[i];
            }
        }
        return ans;
    }
};