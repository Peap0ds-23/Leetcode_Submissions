/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
#include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string fun(string &s){
        if(s.empty()) return "";
        size_t pos = s.find(',');
        if(pos == string::npos){
            string token = s;    // last token
            s.clear();
            return token;
        } else {
            string token = s.substr(0, pos);
            s = s.substr(pos + 1); // remove token + comma
            return token;
        }
    }
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*> q;
        if(!root){
            return s;
        }
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                if(node){
                    s+=(to_string(node->val));
                    s+=",";
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    s+=("N");
                    s+=",";
                }
                q.pop();
            }
        }
        // cout<<s.substr(0,s.size()-1);
        return s.substr(0,s.size()-1);
    }
    // int stoi(string &str){
    //     return 1;
    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        string val=fun(data);
        // char val=data[0];
        // data=data.substr(2);
        TreeNode* root=new TreeNode(stoi(val));
        TreeNode* curr=root;
        queue<TreeNode*> q;
        q.push(curr);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(data.size()>0){
                string val=fun(data);
                if(val=="N"){
                    node->left=NULL;
                }else{
                    node->left=new TreeNode(stoi(val));
                    q.push(node->left);
                }
                
            }
            if(data.size()>0){
                string val=fun(data);
                if(val=="N"){
                    node->right=NULL;
                }else{
                    node->right=new TreeNode(stoi(val));
                    q.push(node->right);
                }
                
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));