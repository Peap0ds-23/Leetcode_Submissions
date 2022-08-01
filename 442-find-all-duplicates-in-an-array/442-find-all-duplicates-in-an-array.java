class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        ArrayList<Integer> list=new ArrayList<>();
        int i=0;
        while(i<nums.length){
            int cor=nums[i]-1;
            if(nums[cor]==nums[i]){
                i++;
                
            }
            else{
                swap(nums,i,cor);
            }
        }
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=j+1){
                list.add(nums[j]);
            }
        }return list;
    }
    public void swap(int[] nums,int i,int cor){
        int temp;
        temp=nums[i];
        nums[i]=nums[cor];
        nums[cor]=temp;
    }
}