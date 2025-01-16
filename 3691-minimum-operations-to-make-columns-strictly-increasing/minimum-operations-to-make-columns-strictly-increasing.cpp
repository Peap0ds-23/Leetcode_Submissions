class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            int minn=grid[0][i];
            for(int j=1;j<m;j++){
                if(grid[j][i]>minn){
                    minn=grid[j][i];
                }else{
                    count+=(minn-grid[j][i]+1);
                    minn+=1;
                }
                // grid[j][i]
            }
        }return count;
    }
};