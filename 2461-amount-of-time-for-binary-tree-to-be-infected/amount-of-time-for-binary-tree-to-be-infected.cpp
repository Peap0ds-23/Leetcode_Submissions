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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* curr=root;
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        // vector<TreeNode*> vis;
        TreeNode* startNode=NULL;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                if(node->val==start){
                    startNode=node;
                }
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
        q.push(startNode);
        unordered_map<TreeNode*,int> vis;
        vis[startNode]=1;
        int time=0;
        while(!q.empty()){
            // k--;
            time++;
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
        // vector<int> ans;

        // while(!q.empty()){
        //     TreeNode* nod=q.front();
        //     q.pop();
        //     ans.push_back(nod->val);
        // }
        return time-1;
    }
};