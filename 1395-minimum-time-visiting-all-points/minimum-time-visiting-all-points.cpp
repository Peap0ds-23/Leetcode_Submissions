class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++){
            int x1=points[i-1][0];
            int y1=points[i-1][1];
            int x2=points[i][0];
            int y2=points[i][1];

            int x=abs(x1-x2);
            int y=abs(y1-y2);
            int rem=abs(x-y);
            ans+=min(x,y)+rem;
        }
        return ans;
    }
};