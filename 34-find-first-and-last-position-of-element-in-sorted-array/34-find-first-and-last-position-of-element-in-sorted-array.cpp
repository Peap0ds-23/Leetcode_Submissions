class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> arr;
        
        // start
        int ans1=-1;
        int st=0,en=nums.size()-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]==target){
                ans1=mid;
                en=mid-1;
            }
            else if(nums[mid]>target){
                en=mid-1;
                
            }
            else{
                st=mid+1;
            }
        }
        arr.push_back(ans1);
        if(ans1==-1){
            arr.push_back(-1);
            return arr;
        }
        // end
        // int ans2;
        ans1=0;
        st=0;
        en=nums.size()-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]==target){
                ans1=mid;
                st=mid+1;
            }
            else if(nums[mid]>target){
                en=mid-1;
                
            }
            else{
                st=mid+1;
            }
        }
        arr.push_back(ans1);
        return arr;
        
    }
};