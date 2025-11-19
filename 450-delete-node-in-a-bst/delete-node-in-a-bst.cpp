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
    TreeNode* deleteNode(TreeNode* curr, int key) {
        // TreeNode* curr=root;
        if(curr){
            if((curr->val)>key){
                curr->left=deleteNode(curr->left,key);
            }else if((curr->val)<key){
                curr->right=deleteNode(curr->right,key);
            }else{
                if(!curr->left && !curr->right){
                    delete curr;
                    return NULL;
                    // break;
                }else if(!curr->left || !curr->right){
                    if(!curr->left){
                        // return curr->right;
                        TreeNode* temp=curr->right;
                        delete curr;
                        return temp;
                    }
                    if(!curr->right){
                        // return curr->left;
                        TreeNode* temp=curr->left;
                        delete curr;
                        return temp;
                    }
                }else{
                    TreeNode* prev=curr->left;
                    while(prev->right){
                        prev=prev->right;
                    }
                    curr->val=prev->val;
                    curr->left=deleteNode(curr->left,curr->val);
                }
                
            }
        }
        return curr;
    }
};