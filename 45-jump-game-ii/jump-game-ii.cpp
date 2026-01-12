class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int st=0,en=0,jump=0,maxx=0;
        while(en<n){
            jump++;
            for(int i=st;i<=en;i++){
                maxx=max(maxx,i+nums[i]);
                if(maxx>=n-1){
                    return jump;
                }
            }
            st=en+1;
            en=maxx;

        }
        return jump;
        
        
        // st=en+1;
        // en=pre_maxx;
    }
};