class Solution {
public:
    int BS(vector<int> &temp,int target){
        int st=0,en=temp.size()-1;
        int ans=-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(temp[mid]==target){
                return mid;
            }else if(temp[mid]>target){
                ans=mid;
                en=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                len++;
                temp.push_back(nums[i]);
            }else{
                int lb=BS(temp,nums[i]);
                temp[lb]=nums[i];
            }
        }
        return len;
    }
};