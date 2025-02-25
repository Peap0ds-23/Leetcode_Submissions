class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0,even=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum &1){
                ans+=even;
                odd++;
            }else{
                ans+=odd;
                even++;
            }
            ans%=((int)(1e9) + 7);
        }return ans;
    }
};