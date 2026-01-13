class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double st=0,en=0,mid,ans=0;
        int n=squares.size(),maxx=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,squares[i][1]+squares[i][2]);
        }
        en=maxx;
        while((en-st)>=1e-5){
            mid=(en+st)/2.0;
            double up=0,down=0;
            for(int i=0;i<n;i++){
                if(squares[i][1]+squares[i][2]<=mid){
                    down+=(double)squares[i][2]*squares[i][2];
                }else if(squares[i][1]>=mid){
                    up+=(double)squares[i][2]*squares[i][2];
                }else{
                    up+=(double)(squares[i][1]+squares[i][2]-mid)*squares[i][2];
                    down+=(double)(mid-squares[i][1])*squares[i][2];
                }
            }
            if(abs(up-down)<=1e-5){
                ans=mid;
                en=mid;
                // return 
            }else if(up>down){
                st=mid;
            }else{
                ans=mid;
                en=mid;
            }
        }
        return ans;

    }
};