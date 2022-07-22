class Solution {
    public int mySqrt(int x) {
        if(x==0){
            return x;
            
        }
        int st=1,en=x,ans=-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(mid==x/mid){
                return mid;
            }
            else if(mid>x/mid){
                en=mid-1;
            }
            else{
                ans=mid;
                st=mid+1;
            }
        }return ans;
    }
}