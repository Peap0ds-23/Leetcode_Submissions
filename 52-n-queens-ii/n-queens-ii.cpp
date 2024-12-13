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
    int findQueen(vector<vector<bool>> &board,int row,int queen){
        if(queen==0){
            return 1;
        }
        int cnt=0;
        if(row==board.size()){
            return 0;
        }

        for(int i=0;i<board.size();i++){
            if(isSafe(board,row,i)){
                board[row][i]=true;
                cnt+=findQueen(board,row+1,queen-1);
                board[row][i]=false;
            }
        }
        return cnt;

    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        return findQueen(board,0,n);
    }
};