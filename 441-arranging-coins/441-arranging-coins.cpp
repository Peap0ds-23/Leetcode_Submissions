class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        double sum=0;
        int p=0;
        while(sum<=n){
            sum+=i;
            i++;
            p++;
        }
        return p-1;
    }
};