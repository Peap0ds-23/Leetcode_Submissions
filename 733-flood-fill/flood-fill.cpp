class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[sr][sc]=1;
        int init=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int nodei=q.front().first;
            int nodej=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=nodei+row[i];
                int nc=nodej+col[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && image[nr][nc]==init){
                    image[nr][nc]=color;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }return image;
    }
};