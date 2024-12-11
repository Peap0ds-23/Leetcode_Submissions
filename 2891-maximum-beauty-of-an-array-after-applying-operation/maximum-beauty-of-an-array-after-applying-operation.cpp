class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,n=nums.size();
        // int i=0;
        int maxx=INT_MIN;
        while(i<n && j<n){
            while(j<n && i<n && nums[j]-nums[i]<=2*k){
                j++;
                maxx=max(maxx,j-i);
            }
            i++;
        }
        return maxx;
    }
};