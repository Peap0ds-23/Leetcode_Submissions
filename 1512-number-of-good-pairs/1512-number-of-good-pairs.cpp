class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
//         int st=0;
//         int en=nums.size();
//         while(st<=en){
            
//         }
        int arr[101];
        for(int i=0;i<101;i++){
            arr[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        int sum=0;
        for(int i=0;i<101;i++){
            if(arr[i]>1){
                int a=arr[i];
                sum+=(a)*(a-1)/2;
            }
        }
        return sum;
        
    }
};