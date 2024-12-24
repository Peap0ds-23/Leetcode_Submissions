class Solution {
public:
// static vector<vector<int>> temp()
    int fun(vector<vector<int>> &arr,int nodei,int nodej, int m,int n){
        if(nodei==m || nodej==n){
            return 0;
        }
        if(nodei==m-1){
            return 1;
        }
        if(nodej==n-1){
            return 1;
        }
        if(arr[nodei][nodej]!=-1){
            return arr[nodei][nodej];
        }
        int count=0;
        count+=fun(arr,nodei+1,nodej,m,n);
        count+=fun(arr,nodei,nodej+1,m,n);
        return arr[nodei][nodej]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        return fun(arr,0,0,m,n);
    }
};