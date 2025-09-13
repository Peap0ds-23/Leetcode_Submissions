class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n=s.size();
        int i=0,j=0,k=2,maxx=1;
        unordered_map<int,int> m;
        while(j<n){
            m[s[j]]++;
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            if(m.size()<=k){
                maxx=max(maxx,(j-i+1));
            }
            j++;
        }
        return maxx;
    }
};