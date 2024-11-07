class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int tm=0;
        while(!q.empty()){
            int time=q.front().first;
            int node_i=q.front().second.first;
            int node_j=q.front().second.second;
            q.pop();
            tm=max(tm,time);
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=row[i]+node_i;
                int nc=col[i]+node_j;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({time+1,{nr,nc}});
                    vis[nr][nc]=1;
                    // grid[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }return tm;
    }
};