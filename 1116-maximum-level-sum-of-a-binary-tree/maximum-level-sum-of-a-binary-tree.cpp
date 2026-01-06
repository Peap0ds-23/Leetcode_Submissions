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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int minn=INT_MIN,ind=-1;
        while(!q.empty()){
            int len=q.size();
            int sum=0;
            int level=q.front().second;
            for(int i=0;i<len;i++){
                TreeNode* node=q.front().first;
                
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push({node->left,level+1});
                }
                if(node->right){
                    q.push({node->right,level+1});
                }
            }
            if(sum>minn){
                ind=level;
                minn=sum;
            }
            // minn=min(minn,sum);
        }
        return ind;
    }
};