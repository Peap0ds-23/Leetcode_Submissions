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
        int ans=fun(root);
        if(ans==-1){
            return false;
        }return true;
    }

    int fun(TreeNode* root){

        if(!root){
            return 0;
        }
        // if(!(root->left) && !(root->right)){
        //     return 1;
        // }
        int left=fun(root->left);
        int right=fun(root->right);
        if(left==-1 || right ==-1){
            return -1;
        }
        if(abs(left-right)<=1){
            return 1+max(left,right);
        }else{
            return -1;
        }
        
    }
};