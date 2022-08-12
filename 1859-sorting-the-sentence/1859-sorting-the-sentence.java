class Solution {
    public String sortSentence(String s) {
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        int i=1;
        StringBuilder sb2=new StringBuilder();
        while(i<10){
            int a=sb.indexOf(String.valueOf(i));
            int b=sb.indexOf(" ",a);
            if(b==-1){
                b=s.length(); 
                // sb2.append(" ");
            }
            if(a==-1){
                break;
            }
            if(i>1){
                sb2.append(" ");
            }
            int en=s.length()-a-1;
            int st=s.length()-b-1;
            sb2.append(s.substring(st+1,en));
            
            i++;
        }return sb2.toString();
        
    }
}