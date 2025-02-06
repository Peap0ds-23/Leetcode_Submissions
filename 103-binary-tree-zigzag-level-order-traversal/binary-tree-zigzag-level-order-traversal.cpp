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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int start=ans.size() & 1;
            // start=start%2;
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                // if(start){
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                // }else{
                //     if(node->right){
                //         q.push(node->right);
                //     }
                //     if(node->left){
                //         q.push(node->left);
                //     }
                // }
                
                temp.push_back(node->val);
            }
            if(start){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
        }return ans;

    }
};