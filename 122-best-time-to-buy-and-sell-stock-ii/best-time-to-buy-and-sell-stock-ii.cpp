class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        int n=prices.size();
        int minn=prices[0];
        int maxx=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>minn){
                sum+=prices[i]-minn;
            }
            minn=prices[i];
        }return sum;
    }
};