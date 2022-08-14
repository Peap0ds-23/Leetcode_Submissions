
class Solution {
    public String freqAlphabets(String s) {
//         for(int i=s.length()-1;i>=0;i++){
            
//         }
        int i=s.length()-1;
        StringBuilder sb=new StringBuilder();
        StringBuilder temp;
        while(i>=0){
            if(s.charAt(i)!='#'){
                int y=s.charAt(i)-'0';
                sb.append((char)(y+96));
                i--;
            }
            else{
                temp=new StringBuilder();
                temp.append(s.charAt(i-2));
                temp.append(s.charAt(i-1));
                sb.append((char)(Integer.valueOf(temp.toString())+96));
                i=i-3;
            }
        }
        return sb.reverse().toString();
    }
}