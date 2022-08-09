class Solution {
    public String longestCommonPrefix(String[] strs) {
        // StringBuilder sb=new StringBuilder();
        if(strs.length==1){
            return strs[0];
        }
        int min=201;
        for(int i=0;i<strs.length;i++){
            min=Math.min(min,strs[i].length());
        }
        if(min<1){
            return "";
        }
        for(int i=0;i<min;i++){
            char ch=strs[0].charAt(i);
            for(int j=1;j<strs.length;j++){
                if(strs[j].charAt(i)!=ch){
                    return strs[0].substring(0,i);
                }
            }
        }
        if(min==1){
            return String.valueOf(strs[0].charAt(0)) ;
        }
        for(int i=0;i<strs.length;i++){
            if(strs[i].length()==min){
                return strs[i];
            }
        }return "";
        
        // String s=new String(strs[0].charAt(0));
        
    }
}