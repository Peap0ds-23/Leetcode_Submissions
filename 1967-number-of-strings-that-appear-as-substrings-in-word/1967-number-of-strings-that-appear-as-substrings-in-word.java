class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int a=0;
        for(String s:patterns){
            if(word.indexOf(s)!=-1){
                a++;
            }
        }return a;
    }
}