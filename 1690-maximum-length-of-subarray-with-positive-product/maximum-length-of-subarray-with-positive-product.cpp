class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size(),curr=-1,ans=0;
        long long pref=1,suff=1;
        for(int i=0;i<n;i++){
            pref*=nums[i];
            if(pref>0){
                ans=max(ans,i-curr);
                pref=1;
            }else if(pref<0){
                pref=-1;
            }
            if(pref==0){
                pref=1;
                curr=i;
            }
        }
        curr=n;
        for(int i=n-1;i>=0;i--){
            suff*=nums[i];
            if(suff>0){
                ans=max(ans,curr-i);
                suff=1;
            }else if(suff<0){
                suff=-1;
            }
            if(suff==0){
                suff=1;
                curr=i;
            }
        }
        return ans;
    }
};