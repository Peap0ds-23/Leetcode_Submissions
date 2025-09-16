class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int st=0,en=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        for(int j=0;j<n;j++){
            int len=ans.size();
            st=0;
            if(j>0 && nums[j]==nums[j-1]){
                st=en+1;
            }
            
            en=len-1;
            for(int i=st;i<=en;i++){
                vector<int> temp=ans[i];
                temp.push_back(nums[j]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};