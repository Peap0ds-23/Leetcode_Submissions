class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minn=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            int mn=nums[i]-k;
            int mx=nums[i]+k;
            if(minn<mn){
                minn=mn;
                count++;
            }else if(minn<mx){
                count++;
                minn=minn+1;
            }
        }return count;
    }
};