class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=K;k++){
                    if(buy==0){
                        dp[i][buy][k]=max(0+dp[i+1][0][k],-prices[i]+dp[i+1][1][k]); 
                    }else{
                        dp[i][buy][k]=max(0+dp[i+1][1][k],prices[i]+dp[i+1][0][k-1]);
                    }
                }
            }
        }
        return dp[0][0][K];
    }
};