class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // int i=0,j=0,n=nums.size();
        // int last=0;
        // while(j<n){
        //     if(nums[j]>last){
        //         j++;
        //         last=nums[j];
        //         maxx=max(maxx,j-1+1);
        //     }else{
        //         last=nums[j];
        //         i=j;
        //         j++;
        //     }



        // }
        int j=0,k=0;
        int inc=0;
        int dec=51;
        int maxx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>inc){
                maxx=max(i-j+1,maxx);
                inc=nums[i];
            }else{
                inc=nums[i];
                j=i;
            }

            if(nums[i]<dec){
                maxx=max(i-k+1,maxx);
                dec=nums[i];
            }else{
                dec=nums[i];
                k=i;
            }
        }return maxx;
    }
};