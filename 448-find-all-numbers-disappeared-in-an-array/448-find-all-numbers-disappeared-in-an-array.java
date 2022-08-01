class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        ArrayList<Integer> list= new ArrayList<>();
        int i=0;
        while(i<nums.length){
            int corr=nums[i]-1;
            if(nums[i]==corr || nums[corr]==nums[i]){
                i++;
            }
            else{
                swap(nums,i,corr);
            }
        }
        
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=j+1){
                list.add(j+1);
            }
        }
        return list;
    }
    
    public void swap(int[] nums,int i,int corr){
        int temp;
        temp=nums[i];
        nums[i]=nums[corr];
        nums[corr]=temp;
    }
}