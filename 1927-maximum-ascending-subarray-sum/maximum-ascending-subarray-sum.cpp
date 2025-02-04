class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0,maxx=0;
        int last=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>last){
                sum+=nums[i];
            }else{
                sum=nums[i];    
            }
            last=nums[i];
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};