class Solution {
public:
    int fun(vector<vector<int>>& grid,vector<vector<int>>& dp, int i,int j,int m, int n){
        if(i==m || j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int sum=grid[i][j];
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        int case1=INT_MAX;
        int case2=INT_MAX;
        if(i<m-1){
            case1=fun(grid,dp,i+1,j,m,n);
        }
        if(j<n-1){
            case2=fun(grid,dp,i,j+1,m,n);
        }
        return dp[i][j]=sum+min(case1,case2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(grid,dp,0,0,m,n);
    }
};