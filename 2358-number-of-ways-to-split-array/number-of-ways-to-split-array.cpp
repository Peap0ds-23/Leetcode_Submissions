class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int count=0;
        int n=nums.size();
        long long int pre=0,post=sum;
        for(int i=0;i<n-1;i++){
            pre+=nums[i];
            post-=nums[i];
            if(pre>=post){
                count++;
            }
        }
        return count;

    }
};