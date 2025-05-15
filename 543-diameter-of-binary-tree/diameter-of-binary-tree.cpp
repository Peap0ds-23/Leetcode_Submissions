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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int val=fun(root,ans);
        return ans;
    }

    int fun(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        if(!(root->left) && !(root->right)){
            return 1;
        }
        int left=fun(root->left,ans);
        int right=fun(root->right,ans);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
};