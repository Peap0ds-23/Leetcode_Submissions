class Solution {
public:
    int dp(int step, int n,vector<int> &arr){
        if(step==n-1 || step==n){
            return 1;
        }
        if(arr[step]!=-1){
            return arr[step];
        }
        return arr[step]=dp(step+1,n,arr)+dp(step+2,n,arr);
    }
    int climbStairs(int n) {
        vector<int> arr(n+1,-1);
        return dp(0,n,arr);
    }
};