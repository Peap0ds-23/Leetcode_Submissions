class Solution {
    public int numIdenticalPairs(int[] nums) {
        int ct=0;
        // for(int i=0;i<nums.length;i++){
        //     for(int j=0;j<nums.length;j++){
        //         if( nums[i]==nums[j] && (i<j)){
        //             ct+=1;
        //             }
        //         }            
        // }
        // return ct;
        
        int i=0,j=1;
        while(i<nums.length-1 && i<j){
            if(nums[i]==nums[j]){
                ct++;
            }
            if(j==nums.length-1){
                i++;
                j=i+1;
            }
            else{
                j++;
            }
        }return ct;
    }
}