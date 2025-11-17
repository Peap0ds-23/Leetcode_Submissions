class Solution {
public:
    int fun(vector<vector<int>>& arr,vector<vector<int>> &dp,int row,int col, int m,int n){
        if(row<0 || row>=m || col>=n || col<0){
            return 0;
        }
        if(arr[row][col]==1){
            return dp[row][col]=0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row==m-1 && col==n-1){
            return dp[row][col]=1;
        }
        
        int count=0;
        if(row+1<m){
            count+=fun(arr,dp,row+1,col,m,n);
        }
        if(col+1<n){
            count+=fun(arr,dp,row,col+1,m,n);
        }
        return dp[row][col]=count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        if(arr[m-1][n-1]==1 || arr[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return fun(arr,dp,0,0,m,n);

    }
};