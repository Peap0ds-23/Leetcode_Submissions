class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int n=words.size();
        int len1=pref.size();
        for(int i=0;i<n;i++){
            int len2=words[i].size();
            if(len2>=len1 && words[i].substr(0,len1)==pref){
                count++;
            }
        }return count;
    }
};