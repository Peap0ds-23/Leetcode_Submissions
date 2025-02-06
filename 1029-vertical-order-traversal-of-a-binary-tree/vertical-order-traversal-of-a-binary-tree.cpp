/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        fun(m,root,0,0);
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> temp;
            for(auto j:i.second){
                // if(j.second.size()==1){
                    sort(j.second.begin(),j.second.end());
                    temp.insert(temp.end(),j.second.begin(),j.second.end());
                // }
            }
            ans.push_back(temp);
        }return ans;
    }
    void fun(map<int,map<int,vector<int>>> &m,TreeNode* curr,int r,int c){
        if(!curr){
            return;
        }
        m[c][r].push_back(curr->val);
        if(curr->left){
            fun(m,curr->left,r+1,c-1);
        }
        if(curr->right){
            fun(m,curr->right,r+1,c+1);
        }
    }
};