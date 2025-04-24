class Solution {
public:
    string smallestPalindrome(string s) {
        map<int,int> m;
        int flag=0,n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]-'a']++;
        }
        string ans="";
        int temp=-1;
        for(int i=0;i<m.size();i++){
            if(m[i]%2){
                temp=i;
            }
            // else{
                int count=m[i]/2;
                while(count){
                    count--;
                    ans+=i+'a';
                }
            // }
        }
        string ans2=ans;
        if(temp>=0){
            ans+=temp+'a';
        }
        reverse(ans2.begin(),ans2.end());
        ans+=ans2;
        return ans;

    }
};