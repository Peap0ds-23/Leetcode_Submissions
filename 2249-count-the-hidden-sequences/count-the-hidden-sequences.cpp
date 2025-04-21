class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        vector<long> range(n+1,0);
        long minn=0;
        long maxx=0;
        for(int i=0;i<n;i++){
            range[i+1]=range[i]+differences[i];
            minn=min(minn,range[i+1]);
            maxx=max(maxx,range[i+1]);
        }
        long gr,ls;
        ls=lower-minn;
        gr=upper-maxx;
        if(gr>=ls){
            return gr-ls+1;
        }return 0;
    }
};