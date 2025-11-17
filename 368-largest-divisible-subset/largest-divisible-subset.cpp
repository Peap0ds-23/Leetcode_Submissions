class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> dp(n,1),prev(n,0);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            prev[i]=i;
            for(int j=0;j<i;j++){
                int a=nums[i];
                int b=nums[j];
                if((a%b==0) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }
        int len=0,ind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>len){
                len=dp[i];
                ind=i;
            }
        }
        while(prev[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=prev[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};