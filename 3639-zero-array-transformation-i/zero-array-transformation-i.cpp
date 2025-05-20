class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //[0,1,2,3]
        //[4,3,2,1]
        //[1,3], [0,2], 
        //[1,2,2,2]
        int n=nums.size();
        vector<int> arr(n+1,0);
        int sz=queries.size();
        for(int i=0;i<sz;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            arr[l]++;
            arr[r+1]--;
        }
        int sum=0;
        for(int i=0;i<=n;i++){
            sum+=arr[i];
            arr[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>arr[i]){
                return false;
            }
        }return true;
    }
};