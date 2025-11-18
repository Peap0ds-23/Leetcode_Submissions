class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size(),len=1,count=1;
        long long ans=0;
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                long temp=count;
                temp*=(count+1);
                temp/=2;
                temp%=mod;
                ans+=(int)(temp);
                count=1;

            }
        }

        long temp=count;
        temp*=(count+1);
        temp/=2;
        temp%=mod;
        ans+=(int)(temp);
        return ans;
    }
};