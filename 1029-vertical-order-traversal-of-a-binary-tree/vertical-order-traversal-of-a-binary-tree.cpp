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
        fun(root,0,0,m);
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto &col:m){
            temp.clear();
            for(auto &row:col.second){
                sort(row.second.begin(),row.second.end());
                for(auto &it:row.second){
                    temp.push_back(it);
                }
            }
            ans.push_back(temp);
        }return ans;
    }

    void fun(TreeNode* root,int r,int c,map<int,map<int,vector<int>>> &m){
        if(!root){
            return;
        }

        m[c][r].push_back(root->val);
        if(root->left){
            fun(root->left,r+1,c-1,m);
        }
        if(root->right){
            fun(root->right,r+1,c+1,m);
        }

    }

};