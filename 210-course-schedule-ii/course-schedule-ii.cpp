class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=n){
            return vector<int>();
        }
        return ans;


    }
};