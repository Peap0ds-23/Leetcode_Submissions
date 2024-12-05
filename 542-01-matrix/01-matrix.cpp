class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    dis[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int nodei=q.front().first.first;
            int nodej=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=nodei+row[i];
                int nc=nodej+col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                    dis[nr][nc]=dist+1;
                }
            }
        }return dis;
    }
};