class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int st=0,en=letters.length-1;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(letters[mid]>target){
                en=mid-1;
            }else{
                st=mid+1;
            }
        }return letters[st%letters.length];
    }
}