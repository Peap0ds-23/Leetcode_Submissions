class Solution {
    public String addBinary(String a, String b) {
        int rem=0,i=a.length()-1,j=b.length()-1;
        StringBuilder sb=new StringBuilder();
        while(i>=0 && j>=0){
            if(rem==0){
                if(a.charAt(i)=='1' && b.charAt(j)=='1'){
                    rem=1;
                    sb.append('0');
                }
                else if(a.charAt(i)=='0' && b.charAt(j)=='0'){
                    rem=0;
                    sb.append('0');
                }
                else{
                    rem=0;
                    sb.append('1');
                }
            }
            else{
                if(a.charAt(i)=='1' && b.charAt(j)=='1'){
                    rem=1;
                    sb.append('1');
                }
                else if(a.charAt(i)=='0' && b.charAt(j)=='0'){
                    rem=0;
                    sb.append('1');
                }
                else{
                    rem=1;
                    sb.append('0');
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            if(rem==1 && a.charAt(i)=='1'){
                rem=1;
                sb.append('0');
            }
            else if(rem==0 && a.charAt(i)=='0'){
                rem=0;
                sb.append('0');
            }
            else{
                rem=0;
                sb.append('1');
            }
            i--;
        }
        while(j>=0){
            if(rem==1 && b.charAt(j)=='1'){
                rem=1;
                sb.append('0');
            }
            else if(rem==0 && b.charAt(j)=='0'){
                rem=0;
                sb.append('0');
            }
            else{
                rem=0;
                sb.append('1');
            }
            j--;
        }
        if(rem==1){
            sb.append('1');
        }return sb.reverse().toString();
    }
}