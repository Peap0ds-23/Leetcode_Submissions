class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        int n=gifts.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        while(k>0){
            int maxx=pq.top();
            int node=floor(sqrt(maxx));
            pq.pop();
            pq.push(node);
            k--;
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }return ans;
    }
};