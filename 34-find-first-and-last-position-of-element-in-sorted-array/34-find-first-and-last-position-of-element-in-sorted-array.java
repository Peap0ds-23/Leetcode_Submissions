class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr=new int[2];
        arr[0]=BS(nums,target,true);
        arr[1]=-1;
        if(arr[0]!=-1){
            arr[1]=BS(nums,target,false);
        }return arr;
        
        
    }
    
    int BS(int[] nums,int target,boolean start){
        int st=0;
        int en=nums.length-1,ans=-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]==target){
                ans=mid;
                if(start==true){
                    en=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else if(nums[mid]>target){
                en=mid-1;
            }
            else {
                st=mid+1;
            }
        }return ans;
    }
}