class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int nums[1001];
        for(int i=0;i<1001;i++){
            nums[i]=0;
        }
        for(int i=0;i<arr.size();i++){
            nums[arr[i]]++;
        }
        int i=1,p=0;
        while(p<=k && i<1001){
            if(nums[i]==0){
                p++;
                if(p==k){
                    return i;
                }
            }
                
                
            i++;
        }
        return 1000+(k-p);
        
    }
};