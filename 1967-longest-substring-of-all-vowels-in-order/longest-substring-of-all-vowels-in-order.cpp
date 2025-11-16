class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> vowel={'a','e','i','o','u'};
        int i=0,j=0,n=word.size(),count=0,st=0,en=0,maxx=0;
        // map<char,int> m;
        
        // if(j==n){
        //     return 0;
        // }
        bool flag;
        while(j<n){
            while(j<n && word[j]!='a'){
                j++;
            }
            // temp=0;
            st=j;
            for(int i=0;i<5;i++){
                flag=false;
                while(j<n && word[j]==vowel[i]){
                    j++;
                    flag=true;
                }
                if(!flag){
                    st=-1;
                    // en=-1;
                    break;
                }
            }
            if(st!=-1){
                maxx=max(maxx,(j-st));
            }
        }
        return maxx;
    }
};