class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int i=1;
        while(i<=(x/i)){
            if(i*i==x){
                return i;
            }
            i++;
        }
        return --i;
    }
};