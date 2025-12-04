class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // vector<pair<int,int>> adj[n];
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,src}});
        vector<int> dist(n,1e9);
        // cout<<dist[1];
        dist[src]=0;
        while(!pq.empty()){
            int stops=pq.front().first;
            int node=pq.front().second.second;
            int dis=pq.front().second.first;
            pq.pop();
            if(stops>k){
                continue;
            }
            // if(stops==k && node==dst){
            //     break;
            // }
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjDis=it.second;
                if(dis+adjDis<dist[adjNode] && stops<=k){
                    dist[adjNode]=dis+adjDis;
                    pq.push({stops+1,{dist[adjNode],adjNode}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};