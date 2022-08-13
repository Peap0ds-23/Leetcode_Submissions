class Solution {
    public boolean areNumbersAscending(String s) {
        // String st=s.replaceAll("[a-z]+","");
        String st=s.replaceAll("[a-z]+","").replaceAll("\s+"," ").trim();
        int i=0,max=0;
        while(i<st.length()){
            if(st.charAt(i)==' '){
                i++;
            }
            else{
                if((i<st.length()-1 && st.charAt(i)!=' ') && st.charAt(i+1)!=' '){
                    int q=((int)st.charAt(i))*10+(int)st.charAt(i+1);
                    if(q>max){
                        max=q;
                        i+=2;
                    }
                    else{
                        return false;
                    }   
                }
                else{
                    int p=(int)st.charAt(i);
                    if(p>max){
                        max=p;
                        i+=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }return true;
        
    }
}