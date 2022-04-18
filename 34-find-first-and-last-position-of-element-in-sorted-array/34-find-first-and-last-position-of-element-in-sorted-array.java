class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr={-1,-1};
        arr[0]=FindIndex(nums,target,true);
        if(arr[0]!=-1){
        arr[1]=FindIndex(nums,target,false);
        }
        return arr;
    }
    
    private int FindIndex(int[] nums,int target,boolean a){
        int ans=-1;
        int start=0;
        int end=nums.length-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }else{
                ans=mid;
                if(a==true){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
                
                
            }
        }return ans;
        
        
    }
    
}