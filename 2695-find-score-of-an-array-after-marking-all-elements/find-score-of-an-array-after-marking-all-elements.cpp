class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int cnt=n;
        vector<bool> temp(n,false);
        while(!pq.empty()){
            int node=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(!temp[ind]){
                temp[ind]=true;
                cnt=cnt-3;
                ans+=node;
                if(ind==0){
                    cnt++;
                }else{
                    temp[ind-1]=true;
                }

                if(ind==n-1){
                    cnt++;
                }else{
                    temp[ind+1]=true;
                }
            }
        }return ans;
    }
};









































// long long ans=0;
//         int n=nums.size();
//         vector<bool> temp(n,false);
//         int rem=n;
//         while(rem>0){
//             int minn=INT_MAX;
//             int ind=-1;
//             for(int i=0;i<n;i++){
//                 if(!temp[i] && nums[i]<minn){
//                     minn=nums[i];
//                     ind=i;
//                 }
//             }
//             ans+=minn;
//             temp[ind]=true;
//             rem=rem-3;
//             if(ind==0){
//                 rem++;
//             }else{
//                 temp[ind-1]=true;
//             }
//             if(ind==n-1){
//                 rem++;
//             }else{
//                 temp[ind+1]=true;
//             }
//         }return ans;