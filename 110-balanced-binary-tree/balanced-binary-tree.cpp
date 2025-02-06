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
    bool isBalanced(TreeNode* root) {
        // int len=0;
        vector<int> ans;
        int len=fun2(root,ans);
        // ans.push_back(len);
        for(int i=0;i<ans.size();i++){
            if(ans[i]>1){
                return false;
            }
        }
        return true;
    }

    int fun2(TreeNode* node,vector<int> & ans){
        if(!node){
            return 0;
        }
        int left=fun2(node->left,ans);
        int right=fun2(node->right,ans);
        ans.push_back(abs(left-right));
        // if(abs(left-right)>1){
        //     return -1;
        // }
        return 1+max(left,right);
    }
};