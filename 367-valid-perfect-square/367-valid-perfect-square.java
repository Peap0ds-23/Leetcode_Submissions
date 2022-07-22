class Solution {
    public boolean isPerfectSquare(int num) {
        int st=1,en=num;
        while(st<=en){
            long mid=st+(en-st)/2;
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid>num){
                en=(int)mid-1;
            }
            else{
                st=(int)mid+1;
            }
        }return false;
    }
}