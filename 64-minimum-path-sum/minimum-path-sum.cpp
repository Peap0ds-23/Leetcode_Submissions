class Solution {
public:
    int fun(vector<vector<int>>& grid,vector<vector<int>> &dp,int row,int col, int m,int n){
        if(row<0 || row>=m || col>=n || col<0){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row==m-1 && col==n-1){
            return dp[row][col]=grid[row][col];
        }
        int count=grid[row][col];
        int r=INT_MAX,c=INT_MAX;
        if(row+1<m){
            r=fun(grid,dp,row+1,col,m,n);
        }
        if(col+1<n){
            c=fun(grid,dp,row,col+1,m,n);
        }
        return dp[row][col]=count+min(r,c);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(grid,dp,0,0,m,n);
    }
};