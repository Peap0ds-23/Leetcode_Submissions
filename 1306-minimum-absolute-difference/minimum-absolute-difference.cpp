class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn=3000000;
        for(int i=0;i<arr.size()-1;i++){
            minn=min(arr[i+1]-arr[i],minn);
        }
        vector<vector<int>> pair;
        vector<int> temp;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==minn){
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                pair.push_back(temp);
                temp.clear();
            }
        }return pair;
        
        
    }
};