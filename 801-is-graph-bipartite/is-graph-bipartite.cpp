class Solution {
public:
    bool dfs(int i,int color,int n,vector<vector<int>>& graph,vector<int> &vis){
        vis[i]=color;
        for(auto it:graph[i]){
            if(!vis[it]){
                if(!dfs(it,-color,n,graph,vis)){
                    return false;
                }
            }else if(vis[it]==color){
                return false;
            }
        }return true;


    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,1,n,graph,vis)){
                    return false;
                }
            }
        }return true;
    }
};