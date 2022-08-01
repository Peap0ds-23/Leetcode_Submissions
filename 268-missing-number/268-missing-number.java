class Solution {
    public int missingNumber(int[] nums) {
        // using cyclic sort
        int i=0;
        while(i<nums.length){
            int correct=nums[i];  
            if(correct<nums.length && correct!=i){
                swap(nums,i,correct);
            }
            else{
                i++;
            }
        }
        
        for(i=0;i<nums.length;i++){
            if(nums[i]!=i){
                return i;
            }
        }return nums.length;
              
    }
    
    public void swap(int[] nums,int i,int correct){
        int temp;
        temp=nums[i];
        nums[i]=nums[correct];
        nums[correct]=temp;
    }
    
}