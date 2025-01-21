// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n=grid[0].size();
//         vector<vector<long long>> temp(2,vector<long long>(n,0));
//         // for(int i=0;i<2;i++){
//             for(int j=0;j<n;j++){
//                 if(j==0){
//                     temp[0][j]=grid[0][j];
//                 }else{
//                     temp[0][j]=temp[0][j-1]+grid[0][j];
//                 }    
//             }
//             for(int j=n-1;j>=0;j--){
//                 if(j==n-1){
//                     temp[1][j]=grid[1][j];
//                 }else{
//                     temp[1][j]=temp[1][j+1]+grid[1][j];
//                 }    
//             }
//         long long maxx=0;
//         int ind=-1;
//         for(int i=0;i<n;i++){
//             if(temp[0][i]+temp[1][i]>maxx){
//                 maxx=temp[0][i]+temp[1][i];
//                 ind=i;
//             }
//         }
//         long long pre=temp[0][ind];
//         long long pos=temp[1][ind];
//         for(int i=0;i<n;i++){
//             if(i<ind){
//                 temp[0][i]=0;
//                 temp[1][i]-=pos;
//             }else if(i>ind){
//                 temp[0][i]-=pre;
//                 temp[1][i]=0;
//             }else{
//                 temp[0][i]=0;
//                 temp[1][i]=0;
//             }
//         }
//         maxx=0;
//         ind=-1;
//         for(int i=0;i<n;i++){
//             if(temp[0][i]+temp[1][i]>maxx){
//                 maxx=temp[0][i]+temp[1][i];
//                 ind=i;
//             }
//         }
//         return maxx;

//         // }
//     }
// };

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = accumulate(begin(grid[0]), end(grid[0]), 0LL), bottomSum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); ++i) {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};