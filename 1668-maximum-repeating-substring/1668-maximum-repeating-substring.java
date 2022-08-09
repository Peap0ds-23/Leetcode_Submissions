class Solution {
    public int maxRepeating(String sequence, String word) {
        if(word.length()>sequence.length()){
            return 0;
        }
        if(sequence.length()==1 && !sequence.equals(word)){
            return 0;
        }
        boolean a;
        for(int i=1;i<=sequence.length();i++){
            a=sequence.contains(word.repeat(i));
            if(!a){
                return i-1;
            }
        }return sequence.length();
    }
}