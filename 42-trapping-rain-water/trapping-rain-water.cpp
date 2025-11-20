class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left,right;
        int n=height.size();
        int maxx=0;
        for(int i=0;i<n;i++){
            left.push_back(maxx);
            maxx=max(maxx,height[i]);
        }
        maxx=0;
        for(int i=n-1;i>=0;i--){
            right.push_back(maxx);
            maxx=max(maxx,height[i]);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int minn=min(left[i],right[i]);
            if(minn>height[i]){
                ans+=(minn-height[i]);
            }
            
        }
        return ans;
    }
};