class Solution {
public:
    int beautySum(string s) {
        int maxx=0;
        int minn=0;
        map<char,int> m;
        int sum=0;
        for(int i=0;i<s.size();i++){
            m.clear();
            for(int j=i;j<s.size();j++){
                m[s[j]]++;
                maxx=INT_MIN;
                minn=INT_MAX;
                for(auto it:m){
                    maxx=max(maxx,it.second);
                    // if(it.second>0){

                    // }
                    minn=min(minn,it.second);
                }
                // cout<<maxx-minn<<" ";
                sum+=(maxx-minn);
            }
            // cout<<"--";
        }return sum;
    }
};