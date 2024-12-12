class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        int n=gifts.size();
        while(k>0){
            int maxx=0;
            int maxi=-1;
            for(int i=0;i<n;i++){
                if(gifts[i]>maxx){
                    maxx=gifts[i];
                    maxi=i;
                }
            }
            gifts[maxi]=floor(sqrt(maxx));
            k--;
        }
        for(int i=0;i<n;i++){
            ans+=gifts[i];
        }return ans;
    }
};