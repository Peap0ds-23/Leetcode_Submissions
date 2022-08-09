class Solution {
    public int lengthOfLastWord(String s) {
        String st=s.trim();
        return st.length()-1-st.lastIndexOf(' ');
    }
}