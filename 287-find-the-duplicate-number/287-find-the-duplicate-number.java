class Solution {
    public int findDuplicate(int[] nums) {
    
        int i=0;
        while(i<nums.length){
            int cor=nums[i]-1;
            if(nums[i]==nums[cor]){
                i++;
                
            }
            else{
                swap(nums,i,cor);
            }        
        }
        return nums[nums.length-1];
    }
    public void swap(int[] nums,int i,int cor){
        int temp;
        temp=nums[i];
        nums[i]=nums[cor];
        nums[cor]=temp;
    }
}