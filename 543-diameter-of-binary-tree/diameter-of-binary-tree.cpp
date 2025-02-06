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
        int maxx=0;
        int len=fun(root,maxx);
        return maxx-1;
    }

    int fun(TreeNode* node,int &maxx){
        if(!node){
            return 0;
        }
        int left=fun(node->left,maxx);
        int right=fun(node->right,maxx);
        maxx=max(maxx,1+left+right);
        return 1+max(left,right);
    }
};