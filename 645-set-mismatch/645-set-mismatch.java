class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] ans=new int[2];
        ans[0]=-1;
        ans[1]=-1;
        int i=0;
        while(i<nums.length){
            int corr=nums[i]-1;
            if(nums[i]==nums[corr]){
                i++;
            }
            else{
                swap(nums,i,corr);
            }
        }
        
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=j+1){
                ans[0]=nums[j];
                ans[1]=j+1;
            }
        }return ans;
    }
    public void swap(int[] nums,int i,int corr){
        int temp;
        temp=nums[i];
        nums[i]=nums[corr];
        nums[corr]=temp;
    }
}