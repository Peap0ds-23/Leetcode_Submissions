class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0,ans=0,count=0;
        map<char,int> m;
        while(j<n){
            m[s[j]]++;
            if(m[s[j]]==1){
                count++;
            }
            while(count==3){
                ans+=(n-j);
                m[s[i]]--;
                if(m[s[i]]==0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};