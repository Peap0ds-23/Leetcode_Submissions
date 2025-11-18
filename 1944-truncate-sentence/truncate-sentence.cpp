class Solution {
public:
    string truncateSentence(string s, int k) {
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                k--;
            }
            if(k==0){
                ind=i;
                break;
            }
        }
        return s.substr(0,ind);
    }
};