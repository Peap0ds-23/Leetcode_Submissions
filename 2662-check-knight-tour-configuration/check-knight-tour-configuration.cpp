class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int row,int col){
        if(row>=0 && row<grid.size() && col>=0 && col<grid.size()){
            return true;
        }return false;
    }
    bool solve(vector<vector<int>>& grid,int row,int col,int count){
        int r[]={-2,-2,-1,-1,1,1,2,2};
        int c[]={-1,1,-2,2,2,-2,1,-1};
        if(count+1==grid.size()*grid.size()){
            return true;
        }
        for(int i=0;i<8;i++){
            int nr=r[i]+row;
            int nc=c[i]+col;
            if(isValid(grid,nr,nc) && grid[nr][nc]==count+1){
                if(solve(grid,nr,nc,count+1)){
                    return true;
                }
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        // int row=0,col=0;
        if(grid[0][0]!=0){
            return false;
        }
        return solve(grid,0,0,0);
    }
};