class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int n2=searchWord.size();
        int i=0;
        int cnt=0;
        while(i<=n-n2){
            cnt++;
            int j=i;
            string str=sentence.substr(i,n2);
            if(str==searchWord){
                return cnt;
            }
            while(j<n && sentence[j]!=' '){
                j++;
            }
            i=j+1;
        }return -1;
    }
};