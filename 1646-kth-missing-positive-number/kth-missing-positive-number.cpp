class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st=0,en=arr.size()-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(arr[mid]-mid-1<k){
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }return k+st;
    }
};