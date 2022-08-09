class Solution {
    public String reversePrefix(String word, char ch) {
        int a=word.indexOf(ch);
        StringBuilder sb=new StringBuilder();
        for(int i=a;i>=0;i--){
            sb.append(word.charAt(i));
        }
        sb.append(word.substring(a+1));
        return sb.toString();
    }
}