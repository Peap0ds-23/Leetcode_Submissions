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
    int lh(TreeNode* root){
        int len=0;
        while(root){
            len++;
            root=root->left;
        }
        return len;
    }
    int rh(TreeNode* root){
        int len=0;
        while(root){
            len++;
            root=root->right;
        }
        return len;
    }
    int fun(TreeNode* root){
        int count=0;
        if(!root){
            return 0;
        }
        // if(!root->left && !root->right){
        //     return 1;
        // }
        int l=lh(root);
        int r=rh(root);
        if(r==l){
            return (1<<l)-1;
        }
        return 1+fun(root->left)+fun(root->right);

    }
    int countNodes(TreeNode* root) {
        int ans=0;
        return fun(root);
    }
};