class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            int k=i;
            int j=0;
            while(k<n && j<n){
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end(),[](int a,int b){
                return a>b;
            });
            k=i;
            j=0;
            int init=0;
            while(k<n && j<n){
                grid[k][j]=temp[init++];
                // temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            temp.clear();
            // for(int j=0;j<=(n-1)/2;j++){

            // }
        }
        for(int i=1;i<n;i++){
            vector<int> temp;
            int k=0;
            int j=i;
            while(k<n && j<n){
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end());
            k=0;
            j=i;
            int init=0;
            while(k<n && j<n){
                grid[k][j]=temp[init++];
                // temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            temp.clear();
        }
        return grid;
    }
};