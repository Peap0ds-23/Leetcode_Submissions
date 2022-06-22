class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=INT_MIN;
        vector<bool> arr;
        for(int i=0;i<candies.size();i++){
            mx=max(mx,candies[i]);
        }
        for(int i=0;i<candies.size();i++){
            if(extraCandies+candies[i]>=mx){
                arr.push_back(true);
            }else{
                arr.push_back(false);
            }
        }
        return arr;
    }
};