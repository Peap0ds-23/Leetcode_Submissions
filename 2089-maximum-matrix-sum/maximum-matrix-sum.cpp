class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minn=INT_MAX,n=matrix.size(),neg=0;
        // bool 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minn=min(minn,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    neg++;
                }
            }
        }
        if(neg%2==0){
            return sum;
        }else{
            return sum-2*minn;
        }
    }
};