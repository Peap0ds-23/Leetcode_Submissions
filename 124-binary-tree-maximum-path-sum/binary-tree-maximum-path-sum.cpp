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
        int maxx=INT_MIN;
        int len=fun(root,maxx);
        // if(maxx<0){
        //     return 0;
        // }
        return maxx;

    }

    int fun(TreeNode* node,int & maxx){
        if(!node){
            return 0;
        }
        int left=fun(node->left,maxx);
        int right=fun(node->right,maxx);
        int sum=node->val+left+right;
        int maximum=max(right+node->val,left+node->val);
        maximum=max(maximum,node->val);
        maximum=max(maximum,sum);
        
        maxx=max(maxx,maximum);
        return (node->val)+max(max(left,right),0);
    }
};
// [2,-1]