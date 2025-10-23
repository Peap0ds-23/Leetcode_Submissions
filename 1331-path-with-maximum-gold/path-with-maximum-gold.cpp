class Solution {
public:
    int fun(vector<vector<int>>& grid, vector<vector<int>>& path, int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        if( r<0 || c<0 || r>=m || c>=n || grid[r][c]==0 || path[r][c]==1){
            return 0;
        }
        path[r][c]=1;
        int sum=grid[r][c];
        int right=fun(grid,path,r,c+1);
        int left=fun(grid,path,r,c-1);
        int up=fun(grid,path,r-1,c);
        int down=fun(grid,path,r+1,c);
        path[r][c]=0;
        return sum+max(right,max(left,max(up,down)));
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> path(m,vector<int>(n,0));
        int maxx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !path[i][j]){
                    int ans=fun(grid,path,i,j);
                    maxx=max(maxx,ans);
                }
            }
        }
        return maxx;
        // return fun(grid,path,0,0);
    }
};