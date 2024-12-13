class Solution {
public:

    bool isSafe(vector<vector<bool>> &board,int row,int col){
        for(int i=0;i<row;i++){
            if(board[i][col]){
                return false;
            }
        }
        int minn=min(row,col);
        for(int i=1;i<=minn;i++){
            if(board[row-i][col-i]){
                return false;
            }
        }
        int n=board.size();
        minn=min(row,n-col-1);
        for(int i=1;i<=minn;i++){
            if(board[row-i][col+i]){
                return false;
            }
        }
        return true;
    }
    void findQueen(vector<vector<bool>> &board,int row,int queen,vector<vector<string>> &ans){
        if(queen==0){
            vector<string> temp;
            int n=board.size();
            for(int i=0;i<n;i++){
                string st="";
                for(int j=0;j<n;j++){
                    if(board[i][j]){
                        st+="Q";
                    }else{
                        st+=".";
                    }
                }
                temp.push_back(st);
            }
            ans.push_back(temp);
        }
        // int cnt=0;

        if(row==board.size()){
            return;
        }

        for(int i=0;i<board.size();i++){
            if(isSafe(board,row,i)){
                board[row][i]=true;
                findQueen(board,row+1,queen-1,ans);
                board[row][i]=false;
            }
        }
        return;

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        vector<vector<string>> ans;
        findQueen(board,0,n,ans);
        return ans;
    }
};