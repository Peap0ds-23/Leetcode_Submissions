class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans=0;
        unordered_map<int,long long> prev;
        for(int i=0;i<tasks.size();i++){
            if(prev.find(tasks[i])!=prev.end()){
                long long next=prev[tasks[i]]+space;
                if(ans>next){
                    prev[tasks[i]]=++ans;
                }else{
                    ans+=next-ans+1;
                    prev[tasks[i]]=ans;
                }
            }else{
                prev[tasks[i]]=++ans;
                // ans++;
            }
        }
        return ans;
    }
};