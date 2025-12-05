class Solution {
public:
    int fun(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j,int m,int n){
        if (i == m - 1) return dp[i][j] = triangle[i][j];
        if (dp[i][j] != INT_MAX) return dp[i][j];

        int left  = fun(triangle, dp, i + 1, j,     m,n);
        int right = fun(triangle, dp, i + 1, j + 1, m,n);

        return dp[i][j] = triangle[i][j] + min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return fun(triangle,dp,0,0,n,n);
    }
};