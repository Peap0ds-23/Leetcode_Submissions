class Solution {
public:
    int jump(vector<int>& nums) {
        int minn=0;
        int minnn=0;
        int maxx=0;
        int maxxx=0;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int i=0;
        int jump=0;
        while(i<n){
            jump++;
            // minn=i+1;
            // maxx=i+nums[i];
            for(int j=minn;j<=maxx;j++){
                minnn=maxx+1;
                maxxx=max(maxxx,j+nums[j]);
            }
            if(n-1>=minnn && n-1<=maxxx){
                return jump;
            }
            i=maxxx+1;
            maxx=maxxx;
            minn=minnn;

        }return jump;
        // for(int i=0;i<n-1;i++){

        // }
    }
};