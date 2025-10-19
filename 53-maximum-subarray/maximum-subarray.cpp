class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        int st=0,en=0,curr;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxx=max(maxx,sum);
            if(sum<0){
                sum=0;
            }
            // if(sum==0){
            //     curr=i;
            // }
            // sum+=nums[i];
            // if(sum>=maxx){
            //     en=i;
            //     maxx=sum;
            // }
            // // maxx=max(maxx,sum);
            // if(sum<0){
            //     sum=0;
            //     st=curr;
            // }
        }return maxx;
    }
};