class Solution {
    public boolean checkString(String s) {
        // int p=s.indexOf('b');
        if(s.indexOf('b')==-1){
            return true;
        }
        // int q=s.indexOf('a',s.indexOf('b'));
        if(s.indexOf('a',s.indexOf('b'))==-1){
            return true;
        }return false;
    }
}
