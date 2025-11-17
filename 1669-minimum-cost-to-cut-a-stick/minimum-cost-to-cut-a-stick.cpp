class Solution {
public:
    int fun(vector<int>& cuts, int i,int j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1];
            cost+=fun(cuts,i,k-1,dp);
            cost+=fun(cuts,k+1,j,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int len=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(len+2,vector<int>(len+2,-1));
        // cuts.push_front(0);
        
        return fun(cuts,1,len,dp);

    }
};