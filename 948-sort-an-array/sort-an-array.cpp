class Solution {
public:
    void mergesort(vector<int>& nums,int st,int en){
        if(st>=en){
            return;
        }
        int mid=st+(en-st)/2;
        mergesort(nums,st,mid);
        mergesort(nums,mid+1,en);
        merge(nums,st,mid,en);
    }
    void merge(vector<int>& nums,int st,int mid,int en){
        vector<int> temp(en-st+1,0);
        int left=st;
        int right=mid+1;
        int k=0;
        while(left<=mid && right<=en){
            if(nums[left]<nums[right]){
                temp[k]=nums[left];
                left++;
            }else{
                temp[k]=nums[right];
                right++;
            }
            k++;
        }
        while(left<=mid){
            temp[k++]=nums[left];
            left++;
        }
        while(right<=en){
            temp[k++]=nums[right];
            right++;
        }
        for(int i=st;i<=en;i++){
            nums[i]=temp[i-st];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        // sort(nums.begin(),nums.end());
        return nums;
    }
};