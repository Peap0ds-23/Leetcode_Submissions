class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto &it:apple){
            sum+=it;
        }
        sort(capacity.begin(),capacity.end(), greater<int>());
        int sum2=0;
        for(int i=0;i<capacity.size();i++){
            sum2+=capacity[i];
            if(sum2>=sum){
                return i+1;
            }
        }
        return 1;
    }
};