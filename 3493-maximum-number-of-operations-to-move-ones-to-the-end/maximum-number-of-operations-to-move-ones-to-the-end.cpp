class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int one=0,ans=0;
        for(int i=0;i<n;i++){
            if(i>0 && s[i]=='1' && s[i-1]=='0'){
                ans+=one;
            }
            if(s[i]=='1'){
                one++;
            }
        }
        if(s[n-1]=='0'){
            ans+=one;
        }
        return ans;
    }
};