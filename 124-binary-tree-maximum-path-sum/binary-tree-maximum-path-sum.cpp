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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        if(!(root->left) && !(root->right)){
            // if((root->val)>0){
                return root->val;
            // }return 0;
        }
        int val=fun(root,ans);
        return ans;
    }

    int fun(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        // if(!(root->left) && !(root->right)){
        //     if((root->val)>0){
        //         return root->val;
        //     }return 0;
        // }
        int left=fun(root->left,ans);
        int right=fun(root->right,ans);
        // int ans=root->val;
        ans=max(ans,root->val);
        ans=max(ans,root->val+left);
        ans=max(ans,root->val+right);
        ans=max(ans,root->val+right+left);
        return max(0,max(root->val,root->val+max(left,right)));
    }
};