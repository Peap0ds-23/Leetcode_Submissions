class Solution {
    public boolean halvesAreAlike(String s) {
        int p=0,q=0;
        for(int i=0;i<s.length()/2;i++){
            switch (s.charAt(i)) {
            case 'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U' -> p++;          
            }
            switch (s.charAt(i+s.length()/2)) {
            case 'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U' -> q++;          
            }
        }
        if(p==q){
            return true;
        }return false;
    }
}