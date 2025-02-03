class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxx=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int maxInd=i+nums[i];
            maxx=max(maxx,maxInd);
            if(i>=maxx){
                return false;
            }
        }return true;
    }
};