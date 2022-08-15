class Solution {
    public boolean judgeCircle(String moves) {
        int i=0,j=0;
        for(int k=0;k<moves.length();k++){
            switch(moves.charAt(k)){
                    case 'R'->i++;
                    case 'L'->i--;
                    case 'U'->j++;
                    case 'D'->j--;
            }
        }
        if(i==0 && j==0){
            return true;
        }return false;
    }
}