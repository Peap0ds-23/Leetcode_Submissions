import java.util.regex.Pattern;
class Solution {
    public boolean isPalindrome(String s) {
        int i=0;
        String str=s.toLowerCase();
        for(int p=i,q=s.length()-1-i;p<=q;p++,q--){
//            int w=s.charAt(p),b=s.charAt(q);

            while(!Pattern.matches("[a-z0-9]",str.subSequence(p,p+1)) && p<s.length()-1){
                p++;
            }
            while(!Pattern.matches("[a-z0-9]", str.subSequence(q,q+1)) && q>0){
                q--;
            }
            int a=(int)(str.charAt(p)-str.charAt(q));
            if(a==0 || q==0 || p==s.length()-1){
                continue;
            }else{
                return false;
            }

        }return true;
    }
}