class Solution {
    public int firstMissingPositive(int[] nums) {
        int i=0;
        while(i<nums.length){
            int corr=nums[i]-1;
            if(nums[i]<1 || nums[i]>nums.length || nums[i]==nums[corr]){
                i++;
            }
            else{
                swap(nums,i,corr);
            }
        }
        for(i=0;i<nums.length;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }return nums.length+1;
    }
    
    
    public void swap(int[] nums,int i,int corr){
        int temp;
        temp=nums[i];
        nums[i]=nums[corr];
        nums[corr]=temp;
    }
}