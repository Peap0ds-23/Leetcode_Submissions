class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=0;
        long long sum=0;
        int maxx=0;
        while(j<n){
            sum+=nums[j];
            long long diff=(j-i+1);
            diff*=nums[j];
            diff-=sum;
            if(diff<=k){
                maxx=max(maxx,j-i+1);
                j++;
            }else{
                while(diff>k){
                    // i++;
                    sum-=nums[i++];
                    diff=(j-i+1);
                    diff*=nums[j];
                    diff-=sum;
                }
                maxx=max(maxx,j-i+1);
                j++;
            }
        }return maxx;
    }
};