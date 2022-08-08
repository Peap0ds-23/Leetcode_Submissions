class Solution {
    public int[] shuffle(int[] nums, int n) {
        for(int i=0;i<n;i++){
            nums[n+i]=nums[n+i]*1024+nums[i];
            
        }
        int p=0;
        for(int i=0;i<nums.length;i=i+2){
            nums[i]=nums[n+p]%1024;
            nums[i+1]=nums[n+p]/1024;
            p++;
        }
        return nums;
    }
}