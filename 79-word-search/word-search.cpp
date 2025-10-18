class Solution {
public:
    bool fun(vector<vector<char>>& board, string word, string curr, int i, int j,vector<vector<int>> &vis,int ind){
        if(ind>=word.size()){
            return false;
        }
        if(word[ind]==board[i][j]){
            curr+=board[i][j];
        }
        if(word==curr){
            return true;
        }
        // string newcurr=curr+board[i][j];
        vis[i][j]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && !vis[nr][nc] && board[nr][nc]==word[ind+1]){
                if(fun(board,word,curr,nr,nc,vis,ind+1)){
                    return true;
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && fun(board,word,"",i,j,vis,0)){
                    return true;
                }
            }
        }
        return false;
    }
};