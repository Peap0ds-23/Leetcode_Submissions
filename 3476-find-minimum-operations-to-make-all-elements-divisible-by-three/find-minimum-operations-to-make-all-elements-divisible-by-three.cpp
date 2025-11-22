class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            int temp=(nums[i]%3);
            ans+=min(temp,3-temp);
        }
        return ans;
    }
};