class Solution {
public:
    int numSub(string s) {
        int n=s.size(),count=0;
        long ans=0;
        for(int j=0;j<n;j++){
            if(s[j]=='0'){
                long temp=count;
                temp*=(count+1);
                temp/=2;
                ans+=temp;
                ans%=(int)(1e9+7);
                count=0;
            }else{
                count++;
            }
        }
        long temp=count;
                temp*=(count+1);
                temp/=2;
                ans+=temp;
        ans%=(int)(1e9+7);
        return (int)ans;
    }
};