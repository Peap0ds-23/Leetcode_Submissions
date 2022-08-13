class Solution {
    public String reverseStr(String s, int k) {
        StringBuilder sb=new StringBuilder(s);
        StringBuilder sb2;
        int i=0;
        while(i<s.length()){
            
            if((i+k)<s.length()){
                sb2=new StringBuilder(s.substring(i,i+k));
                sb.replace(i,i+k,sb2.reverse().toString());
                i+=2*k;
            }
            else{
                sb2=new StringBuilder(s.substring(i,s.length()));
                sb.replace(i,s.length(),sb2.reverse().toString());
                break;
            }
        }return sb.toString();
    }
}