class Solution {
public:
    int fun(vector<vector<int>> &dp, int row,int col, int m,int n){
        if(row<0 || row>=m || col>=n || col<0){
            return 0;
        }
        if(row==m-1 || col==n-1){
            return dp[row][col]=1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int count=0;
        if(row+1<m){
            count+=fun(dp,row+1,col,m,n);
        }
        if(col+1<n){
            count+=fun(dp,row,col+1,m,n);
        }
        return dp[row][col]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(dp,0,0,m,n);
    }
};