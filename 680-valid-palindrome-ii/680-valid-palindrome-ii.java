class Solution {
    public boolean validPalindrome(String s) {
        int p=0,q=s.length()-1;
        boolean a=false;
        for(int i=0;i<s.length()/2;i++)
            {
                if(s.charAt(i)!=s.charAt(s.length()-1-i)){
                    p=i;
                    q=s.length()-1-i;
                    a=true;
                    break;
                }
            } 
        if(!a){
            return true;
        }   
//         for(int i=0;i<s.length();i++){
            
//             String str=s.substring(0,i)+s.substring(i+1,s.length());
            
//             a=0;
//             for(int j=0;j<str.length()/2;j++)
//             {
//                 if(str.charAt(j)==str.charAt(str.length()-1-j)){
//                     a++;
//                 }
//             } 
//             if(a==str.length()/2){
//                 return true;
//             }
//         }return false;
        String str=s.substring(0,p)+s.substring(p+1,s.length());
        a=false;
        for(int i=0;i<str.length()/2;i++)
            {
                if(str.charAt(i)!=str.charAt(str.length()-1-i)){
                    a=true;
                    break;
                }
            } 
        if(!a){
            return true;
        }
        
        str=s.substring(0,q)+s.substring(q+1,s.length());
        a=false;
        for(int i=0;i<str.length()/2;i++)
            {
                if(str.charAt(i)!=str.charAt(str.length()-1-i)){
                    a=true;
                    break;
                }
            } 
        if(!a){
            return true;
        }
        return false;
    }
}