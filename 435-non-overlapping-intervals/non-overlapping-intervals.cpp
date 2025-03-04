class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=maxx){
                maxx=intervals[i][1];
            }else{
                count++;

            }
        }return count;
    }
};