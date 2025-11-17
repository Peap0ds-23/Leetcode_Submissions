class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int up=(i==0 || matrix[i-1][j]=='0')?0:dp[i-1][j];
                    int left=(j==0 || matrix[i][j-1]=='0')?0:dp[i][j-1];
                    int dia=((i==0 || j==0) || matrix[i-1][j-1]=='0')?0:dp[i-1][j-1];

                    dp[i][j]=1+min(up,min(left,dia));
                }else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
                // cout<<dp[i][j]<<" ";

            }
            // cout<<endl;
        }
        return ans*ans;
    }
};