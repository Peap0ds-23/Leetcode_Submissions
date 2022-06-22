class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx=INT_MIN;
        for(vector<int> & account:accounts){
            int sum=0;
            
            for(int money:account){
                sum+=money;
            }
            mx=max(mx,sum);
        }
        return mx;
    }
};