class Solution {
public:
    bool fun(vector<string>& nums,int i,int j){
        string s1=nums[i];
        string s2=nums[j];
        if(s1.size() != s2.size() + 1) return false;
    
        int first = 0;
        int second = 0;
    
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false;
        
    }
    // bool comp(string &s1,string &s2){
    //     return s1.size()<s2.size();
    // }
    int longestStrChain(vector<string>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> dp(n,1),prev(n,0);
        sort(nums.begin(),nums.end(),[](string &s1,string &s2){
        return s1.size()<s2.size();
    });
        for(int i=1;i<n;i++){
            // prev[i]=i;
            for(int j=0;j<i;j++){
                // int a=nums[i];
                // int b=nums[j];
                if(fun(nums,i,j) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    // prev[i]=j;
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
        // while(prev[ind]!=ind){
        //     ans.push_back(nums[ind]);
        //     ind=prev[ind];
        // }
        // ans.push_back(nums[ind]);
        // reverse(ans.begin(),ans.end());
        return len;
    }
};