class Solution {
public:
    int fun(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j,int m,int n){
        if(i<0 || i>=n || j<0 || j>i){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=fun(triangle,dp,i+1,j,m,n)+triangle[i][j];
        int right=fun(triangle,dp,i+1,j+1,m,n)+triangle[i][j];
        return dp[i][j]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(triangle,dp,0,0,n,n);
    }
};