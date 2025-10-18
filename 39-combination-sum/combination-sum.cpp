class Solution {
public:
    void fun(vector<int>& candidates, int target,int ind,vector<int>& curr,vector<vector<int>> &ans){
        if(ind<0){
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(candidates[ind]<=target){
            fun(candidates,target,ind-1,curr,ans);
            curr.push_back(candidates[ind]);
            fun(candidates,target-candidates[ind],ind,curr,ans);
            curr.pop_back();
        }else{
            fun(candidates,target,ind-1,curr,ans);
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> curr;
        fun(candidates,target,n-1,curr,ans);
        return ans;
    }
};