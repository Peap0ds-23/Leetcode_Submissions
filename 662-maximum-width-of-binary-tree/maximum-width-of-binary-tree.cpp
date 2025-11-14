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
    int widthOfBinaryTree(TreeNode* root) {
        int maxx=0;
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int len=q.size();
            int first=0,last=0;
            // int minInd=q.front().second;
            for(int i=0;i<len;i++){
                // pair<TreeNode*,int> it=q.front();
                
                TreeNode* node=q.front().first;
                
                long val=q.front().second;
                q.pop();
                if(i==0){
                    first=val;
                }
                if(i==len-1){
                    last=val;
                }
                val-=first;
                if(node->left){
                    q.push({node->left,2*val+1});
                }
                if(node->right){
                    q.push({node->right,2*val+2});
                }
            }
            maxx=max(maxx,(last-first+1));
        }
        return maxx;
    }
};