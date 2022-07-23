class Solution {
    public int findKthPositive(int[] arr, int k) {
       
        // let us try to do in log n timee complexity
        // but here is the space complexity of n
        int[] nums=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            nums[i]=arr[i]-i-1;
            
        }
        int st=0,en=nums.length-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]>=k){
                // ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
                
            }
        }
        return st+k;
    }
}