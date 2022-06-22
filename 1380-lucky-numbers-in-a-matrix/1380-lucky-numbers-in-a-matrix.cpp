class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> arr;
        for(int i=0;i<matrix.size();i++){
            int mn=INT_MAX,k=0;
            for(int j=0;j<matrix[0].size();j++){
                
                if(mn>matrix[i][j]){
                    mn=matrix[i][j];
                    k=j;
                }
            }
            int mx=mn;
            for(int p=0;p<matrix.size();p++){
                mx=max(mx,matrix[p][k]);
            }
            if(mx==mn){
                arr.push_back(mx);
            }
        }
        return arr;
    }
};
