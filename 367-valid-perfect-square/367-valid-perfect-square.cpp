class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(i<=(num/i)){
            if(i*i==num){
            return true;
            }
            i++;
        }
        return false;
        
    }
};