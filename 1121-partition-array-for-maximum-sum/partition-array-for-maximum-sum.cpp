class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int maxx=0;
            for(int j=i-1;j>=max(0,i-k);j--){
                maxx=max(maxx,arr[j]);
                dp[i]=max(dp[i],dp[j]+(i-j)*maxx);
            }
            // for(int j=max(0,i-k);j<i;j++){
            //     maxx=max(maxx,arr[j]);

            // }
        }
        return dp[n];
    }
};