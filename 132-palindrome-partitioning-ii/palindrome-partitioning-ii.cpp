class Solution {
public:
    bool isPalin(string &s, int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int fun(vector<vector<int>> &dp,string s,int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=j || isPalin(s,i,j)){
            return dp[i][j]=0;
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalin(s,i,k)){
                if(dp[k+1][j]==-1){
                    dp[k+1][j]=fun(dp,s,k+1,j);
                }
                int count=1+dp[k+1][j];
                ans=min(ans,count);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(dp,s,0,n-1);
    }
};