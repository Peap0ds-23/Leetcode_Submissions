/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* curr=root;
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        // vector<TreeNode*> vis;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                if(node->left){
                    q.push(node->left);
                    parent[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right]=node;
                }
                q.pop();
            }
        }
        q.push(target);
        unordered_map<TreeNode*,int> vis;
        vis[target]=1;
        while(!q.empty() && k>0){
            k--;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && vis.find(temp->left)==vis.end()){
                    vis[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right && vis.find(temp->right)==vis.end()){
                    vis[temp->right]=1;
                    q.push(temp->right);
                }
                if(parent[temp] && vis.find(parent[temp])==vis.end()){
                    vis[parent[temp]]=1;
                    q.push(parent[temp]);
                }

            }
        }
        vector<int> ans;

        while(!q.empty()){
            TreeNode* nod=q.front();
            q.pop();
            ans.push_back(nod->val);
        }
        return ans;
        
    }
};