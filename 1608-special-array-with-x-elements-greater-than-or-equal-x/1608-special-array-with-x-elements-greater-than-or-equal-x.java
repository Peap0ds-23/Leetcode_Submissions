class Solution {
    public int specialArray(int[] nums) {
        int st=1,en=nums.length;
        while(st<=en){
            int x=st+(en-st)/2;
            int p=0;
            for(int i:nums){
                if(i>=x){
                    p++;
                }
            }
            if(p==x){
                return x;
            }
            else if(p>x){
                st=x+1;
            }
            else{
                en=x-1;
            }
            
        }return -1;
        
    }
}