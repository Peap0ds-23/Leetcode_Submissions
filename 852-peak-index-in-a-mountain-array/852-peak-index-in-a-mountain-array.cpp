class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0,en=arr.size()-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(st==en){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]){
                en=mid;
            }
            else if(arr[mid]<arr[mid+1]){
                
                st=mid+1;
            }
        }return -1;
    }
};