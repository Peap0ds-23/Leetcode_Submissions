class Solution {
    public String reverseWords(String s) {
        StringBuilder sb;
        StringBuilder sb2=new StringBuilder();
        int i=0;
        while(i<s.length()){
            if(i!=0){
                sb2.append(' ');
            }
            int j=i;
            while(j<s.length() && s.charAt(j)!=' '){
                j++;
            }
            sb=new StringBuilder(s.substring(i,j));
            sb2.append(sb.reverse().toString());
            
            i=j+1;
        }return sb2.toString();
    }
}