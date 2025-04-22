class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans=0;
        int n=values.size();
        vector<int> vis(n,0);
        int i=0;
        while(i>=0 && i<n && !vis[i]){
            if(instructions[i]=="add"){
                vis[i]=1;
                ans+=values[i];
                i++;
            }else{
                vis[i]=1;
                i=i+values[i];
            }
        }
        return ans;

    }
};