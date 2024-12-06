class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> dis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=1e9;
            }
        }
        dis[0][0]=1;
        if(grid[0][0]==1){
            return -1;
        }
        while(!q.empty()){
            int nodei=q.top().second.first;
            int nodej=q.top().second.second;
            int dist=q.top().first;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=nodei+i;
                    int nc=nodej+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && dist+1<dis[nr][nc] && !grid[nr][nc]){
                        dis[nr][nc]=dist+1;
                        q.push({dist+1,{nr,nc}});
                    }
                }
            }

        }
        if(dis[n-1][n-1]==1e9){
            return -1;
        }
        return dis[n-1][n-1];

    }
};