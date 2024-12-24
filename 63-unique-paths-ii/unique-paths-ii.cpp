class Solution {
public:
    int fun(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int i,int j,int m,int n){
        if(i==m || j==n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            if(obstacleGrid[i][j]){
                return 0;
            }
            return 1;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int count=0;
        if(i<m-1){
            count+=fun(obstacleGrid,dp,i+1,j,m,n);
        }
        if(j<n-1){
            count+=fun(obstacleGrid,dp,i,j+1,m,n);
        }
        return dp[i][j]=count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fun(obstacleGrid,dp,0,0,m,n);
    }
};