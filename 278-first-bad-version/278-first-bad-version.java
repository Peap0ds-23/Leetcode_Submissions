/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int st=1,en=n,ans=-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            boolean a=isBadVersion(mid);
            if(a==true){
                ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }return ans;
    }
}