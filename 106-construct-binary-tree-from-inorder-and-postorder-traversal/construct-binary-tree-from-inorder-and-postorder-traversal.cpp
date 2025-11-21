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
    // int BS(vector<int>& inorder,int st,int en,int target){
    //     if(st>en){
    //         return -1;
    //     }
    //     if(st==en && inorder[st]==target){
    //         return st;
    //     }
    //     // else if(st==en && inorder[st]!=target){
    //     //     return -1;
    //     // }
    //     while(st<=en){
    //         int mid=st+(en-st)/2;
    //         if(inorder[mid]==target){
    //             return mid;
    //         }else if(inorder[mid]>target){
    //             en=mid-1;
    //         }else{
    //             st=mid+1;
    //         }
    //     }
    //     return -1;
    // }
    TreeNode* fun(vector<int>& inorder,int st1,int en1,vector<int>& postorder,int st2,int en2,unordered_map<int, int> &hm){
        if(st2>en2 || st1>en1){
            return NULL;
        }
        if(st2==en2){
            return new TreeNode(postorder[st2]);
        }
        int curr=postorder[en2];
        TreeNode* node= new TreeNode(curr);
        int currIndexInOrder=hm[postorder[en2]];//BS(inorder,st1,en1,curr);
        int len=currIndexInOrder-st1;
        node->left=fun(inorder,st1,currIndexInOrder-1,postorder,st2,st2+len-1,hm);
        node->right=fun(inorder,currIndexInOrder+1,en1,postorder,st2+len,en2-1,hm);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        unordered_map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }
        // if(n==0){

        // }
        // int curr=postorder(n-1);
        // TreeNode* node= new TreeNode(curr);
        // int currInoder=BS(inorder,curr);
        // int leftLen=currInoder;
        // int rightLen=len-leftLen-1;
        // int leftPostorder=currInoder-1;
        // itn right=currInoder+1;
        return fun(inorder,0,n-1,postorder,0,n-1,hm);
    }
};