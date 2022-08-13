class Solution {
    public boolean checkString(String s) {
        int p=s.indexOf('b');
        if(p==-1){
            return true;
        }
        int q=s.indexOf('a',p);
        if(q==-1){
            return true;
        }return false;
    }
}