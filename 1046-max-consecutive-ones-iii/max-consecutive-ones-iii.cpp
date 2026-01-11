class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),zero=0,one=0,i=0,j=0,mx=0;
        while(j<n){
            if(nums[j]==0){
                zero++;
            }
            // else{
            //     one++;
            // }
            while(zero>k){
                if(nums[i]==0){
                    zero--;
                }
                // else{
                //     one--;
                // }
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};