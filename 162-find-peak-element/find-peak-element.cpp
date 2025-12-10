class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st=0,en=nums.size()-1,mid=0;
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }
        while(st<=en){
            mid=st+(en-st)/2;
            if((mid>0) && nums[mid]>nums[mid-1] && (mid+1<nums.size()) && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if((mid>0) && nums[mid]>nums[mid-1]){
                st=mid;
            }
            else{
                en=mid;
            }
        }return mid;
    }
};