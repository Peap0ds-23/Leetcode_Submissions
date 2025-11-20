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
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        stack<TreeNode*> st1,st2;
        TreeNode* temp1=root,*temp2=root;
        while(true){
            while(temp1){
                st1.push(temp1);
                temp1=temp1->left;
            }
            while(temp2){
                st2.push(temp2);
                temp2=temp2->right;
            }
            if(st1.empty() || st2.empty()){
                return false;
            }
            temp1=st1.top();
            temp2=st2.top();
            if((temp1->val +temp2->val)==k){
                if(temp1 ==temp2){
                    return false;
                }
                return true;
            }else if((temp1->val +temp2->val)<k){
                st1.pop();
                temp1=temp1->right;
                temp2=NULL;
            }else{
                st2.pop();
                temp2=temp2->left;
                temp1=NULL;
            }
        }
        return false;
    }
};