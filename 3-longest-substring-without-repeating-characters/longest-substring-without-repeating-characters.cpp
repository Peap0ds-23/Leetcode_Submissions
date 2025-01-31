class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        map<int,int> m;
        // set<int> s;
        int maxx=0;
        while(j<n){
            m[s[j]-'a']++;
            // s.insert(s[j]-'a');
            // if(s.find(s[j]-'a'))
            if(m[s[j]-'a']<1){
                j++;
            }else if(m[s[j]-'a']==1){
                maxx=max(maxx,j-i+1);
                j++;
            }else{
                while(m[s[j]-'a']>1){
                    m[s[i]-'a']--;
                    i++;
                    // i--;
                }
                j++;
            }
        }return maxx;
    }
};