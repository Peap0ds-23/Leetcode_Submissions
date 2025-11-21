class Solution {
public:
    int fun(vector<int>& nums, int k){
        int n=nums.size(),i=0,j=0,count=0,ans=0;
        unordered_map<int,int> m;
        
        while(j<n){
            m[nums[j]]++;
            if(m[nums[j]]==1){
                count++;
            }
            while(count>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    count--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
        
    }
};