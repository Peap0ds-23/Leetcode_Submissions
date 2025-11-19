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
    TreeNode* fun(vector<int>& preorder,int st,int en){
        if(st>en){
            return NULL;
        }

        
        // int pivot= //find the floor of the preorder[st]
        int ref=preorder[st];
        // int low=st+1;
        // int high=en;
        int pivot;
        // cout<<pivot<<endl;
        for(int i=st;i<=en;i++){
            if(preorder[i]>preorder[st]){
                pivot=i;
                break;
            }
        }
        TreeNode* node=new TreeNode(preorder[st]);
        node->left=fun(preorder,st+1,pivot-1);
        node->right=fun(preorder,pivot,en);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int en=preorder.size();
        return fun(preorder,0,en-1);
        // TreeNode* node=new TreeNode(preorder[0]);

    }
};