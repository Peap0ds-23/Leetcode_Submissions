class Solution {
public:
    bool dfs(int node, vector<int>& vis,vector<int>& pathvis,vector<vector<int>>&adj,vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(!dfs(it,vis,pathvis,adj,ans)){
                    return false;
                }
            }else if(pathvis[it]){
                return false;
            }
        }
        ans.push_back(node);
        pathvis[node]=0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int n=numCourses;
        vector<int> vis(n,0);
        vector<int> ans;
        vector<int> pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,vis,pathvis,adj,ans)){
                    return vector<int>();
                }
            }
        }return ans;
    }
};