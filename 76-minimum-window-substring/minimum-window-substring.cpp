class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),count=0;
        unordered_map<int,int> m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
            if(m[t[i]]==1){
                count++;
            }
        }
        int i=0,j=0,minn=INT_MAX,maxx=-1;
        int st=-1,en=-1;
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    // m.erase(s[j]);
                    count--;
                }
            }
            while(count==0){
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                if((j-i+1)<minn){
                    minn=j-i+1;
                    st=i;
                    en=j;
                }
                minn=min(minn,(j-i+1));
                i++;
            }
            j++;
        }
        if(st==-1 && en==-1){
            return "";
        }
        return s.substr(st,(en-st+1));
        // cout<<minn;
        // return "s";
    }
};