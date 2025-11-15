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
    int BS(vector<int> &inorder, int target, bool flag){
        int st=0,en=inorder.size()-1;
        int ans=-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(inorder[mid]==target){
                return target;
            }else if(inorder[mid]>target){
                if(flag){
                    ans=inorder[mid];
                }
                en=mid-1;
            }else{
                if(!flag){
                    ans=inorder[mid];
                }
                st=mid+1;
            }

        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder;
        TreeNode* curr=root;
        while(curr){
            if(curr->left== NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        // for(auto it: inorder){
        //     cout<<it<< ", ";
        // }
        vector<vector<int>> ans;
        for(auto it:queries){
            int lb=BS(inorder,it,false);
            int ub=BS(inorder,it,true);
            
            ans.push_back({lb,ub});
        }
        
        return ans;
    }
};