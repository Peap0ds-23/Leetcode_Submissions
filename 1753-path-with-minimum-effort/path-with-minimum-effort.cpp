class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        // priority_queue<>
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> dis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=1e9;
            }
        }
        dis[0][0]=0;
        while(!q.empty()){
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            // if(r==m-1 && c==n-1){
            //     break;
            // }
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n ){
                    int diff=abs(heights[nr][nc]-heights[r][c]);
                    int maxx=max(diff,dist);
                    if(maxx<dis[nr][nc]){
                        dis[nr][nc]=maxx;
                        q.push({maxx,{nr,nc}});
                    }
                }
            }
        }
        // int minn=INT_MAX;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dis[i][j]=1e9;
        //     }
        // }
        return dis[m-1][n-1];
    }
};