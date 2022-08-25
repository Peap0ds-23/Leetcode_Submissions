class Solution {
    public boolean check(int[] nums) {
        int max=0,index=-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=max){
                max=nums[i];
                index=i;
            }
        }
        if(index!=nums.length-1){
            swap(nums,0,nums.length-1);
            swap(nums,0,nums.length-2-index);
            swap(nums,nums.length-index-1,nums.length-1);
        }
        
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]!=max){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
        }return true;  
   }
    
    public void swap(int[] arr,int st,int en){
        while(st<en){
            int temp=arr[st];
            arr[st]=arr[en];
            arr[en]=temp;
            st++;
            en--;
        }
    }
}


// [3,4,5,1,2]
// [2,1,3,4]
// [1,2,3]
// [1,2,3,4,5]
// [5,4,3,2,1]
// [1,2,3,1]
// [2,4,5,6,5]
// [2,2,2,2]
// [2,2,2,12]
// [5,5,4,3,2,1]
// [4,1,5,5,3,2]
// [4,1,1,5,3,2]
// [4,1,1,5,5,3,2]
// [4,1,5,1,5,2,3]
// [4,1,5,1,5,3,2]
// [4,1,5,1,5,3,3,2]
// [3,4,5,5,1,2]
// [3,4,5,5,2,1,2]
// [43,45,67,85,4,7,9,1]
// [43,45,67,85,4,7,9]
// [3,3,5,5,5]
// [3,3,4,5]
// [2,2,5,5,55,1]
// [3,3,5,5,6,6,7,7,2,2,2,2,2,2,2,2,2,1]
// [3,3,5,5,6,6,7,7,2,2,2,2,2,2,2,2,2,2,1,1]
// [10,10,1,2,2,4,5,10]
// [10,10,1,2,2,4,5,10,10,10]
// [10,10,10,10,2,2,2]
// [10,2,1]
// [10,1,4,5,10]



