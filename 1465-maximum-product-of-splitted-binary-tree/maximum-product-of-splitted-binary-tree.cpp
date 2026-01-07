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
    long long inorder(TreeNode* root,unordered_set<int> &s){
        if(!root){
            return 0;
        }
        long long temp=0;
        temp+=inorder(root->left,s);
        temp+=root->val;
        temp+=inorder(root->right,s);
        s.insert(temp);
        return temp;
    }
    int maxProduct(TreeNode* root) {
        long long sum=0;
        unordered_set<int> s;
        sum=inorder(root, s);
        cout<<sum;
        long long maxx=0;
        auto it=s.begin();
        while(it!=s.end()){
            long long val=*(it);
            maxx=max(maxx,val*(sum-val));
            it++;
        }
        int mod=(1e9+7);
        return maxx%mod;
    }
};