class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                // for(int k=1;k<=2;k++){
                    if(buy==0){
                        dp[i][buy]=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]); 
                    }else{
                        dp[i][buy]=max(0+dp[i+1][1],prices[i]+dp[i+2][0]);
                    }
                // }
            }
        }
        return dp[0][0];
    }
};