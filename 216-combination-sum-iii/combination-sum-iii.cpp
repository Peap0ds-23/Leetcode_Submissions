class Solution {
public:
    void fun(int k, int n, int sum,int ind,vector<int> temp,vector<vector<int>> &ans){
        
        if(temp.size()==k && sum==n){
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k || sum>n || ind>9){
            return;
        }
        
        fun(k,n,sum,ind+1,temp,ans);
        temp.push_back(ind);
        fun(k,n,sum+ind,ind+1,temp,ans);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(k,n,0,1,temp,ans);
        return ans;
    }
};