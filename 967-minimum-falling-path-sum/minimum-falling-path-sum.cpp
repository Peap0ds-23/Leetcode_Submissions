class Solution {
public:
    int fun(int r,int c,int n,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(r==n){
            return 0;
        }
        int minn=INT_MAX;
        if(dp[r][c]!=100000){
            return dp[r][c];
        }
        if(c-1>=0){
            minn=min(minn,fun(r+1,c-1,n,matrix,dp)+matrix[r][c]);
        }
        minn=min(minn,fun(r+1,c,n,matrix,dp)+matrix[r][c]);
        if(c+1<n){
            minn=min(minn,fun(r+1,c+1,n,matrix,dp)+matrix[r][c]);
        }
        return dp[r][c]=minn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int minn=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,100000));
        for(int i=0;i<n;i++){
            minn=min(minn,fun(0,i,n,matrix,dp));
        }
        return minn;

    }
};