class Solution {
public:
    void dfs(int i,int n,vector<int> &vis,vector<vector<int>> &adj ){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,n,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,n,vis,adj);
            }
        }
        return cnt;
    }
};