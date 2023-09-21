class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        char c=board[0][0];
        string s="";
        s+=c;
        if(m==1 && n==1 && word==s){
            return true;
        }
        vector<vector<bool>> flag;
        for(int i=0;i<m;i++){
            vector<bool> v(n,false);
            flag.push_back(v);
            v.clear();
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(fun(board,flag,word,i,j)){
                    return true;
                }
            }
        }return false;
    }

    bool fun(vector<vector<char>>& board,vector<vector<bool>>& flag, string word,int r,int c){
        if(word.size()==0){
            return true;
        }
        char ch=word[0];
        if(ch!=board[r][c]){
            return false;
        }
        if(flag[r][c]){
            return false;
        }
        flag[r][c]=true;

        bool flag2=false;
        if(c<board[0].size()-1){
            flag2=fun(board,flag,word.substr(1),r,c+1);
        }
        if(flag2){
            return true;
        }
        if(r<board.size()-1){
            flag2=fun(board,flag,word.substr(1),r+1,c);
        }
        if(flag2){
            return true;
        }
        if(c>0){
            flag2=fun(board,flag,word.substr(1),r,c-1);
        }
        if(flag2){
            return true;
        }
        if(r>0){
            flag2=fun(board,flag,word.substr(1),r-1,c);
        }
        if(flag2){
            return true;
        }
        flag[r][c]=false;
        return false;
    }
};