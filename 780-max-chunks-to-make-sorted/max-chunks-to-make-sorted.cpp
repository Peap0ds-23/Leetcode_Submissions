class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int prefixsum=0;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=i;
            prefixsum+=arr[i];
            if(sum==prefixsum){
                count++;
            }
        }return count;
    }
};