class Solution {
    public boolean checkOnesSegment(String s) {
        int i=s.indexOf('0');
        if(i==-1){
            return true;
        }
        int a=s.indexOf('1',i);
        if(a==-1){
            return true;
        }return false;
    }
}