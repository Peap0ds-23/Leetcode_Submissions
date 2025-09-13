class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<int,int> m;
        int count=0;
        int maxx=0;
        while(j<n){
            if(m.find(s[j])==m.end()){
                count++;
            }
            m[s[j]]++;
            while((j-i+1)>count){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                    count--;
                }
                i++;
            }
            if((j-i+1)==count){
                maxx=max(maxx,(j-i+1));
            }
            j++;
        }return maxx;
    }
};