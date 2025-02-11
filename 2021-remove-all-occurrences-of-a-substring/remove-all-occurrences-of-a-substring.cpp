class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp="";
        int n=part.size();
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            int a=temp.size();
            if(a>=n && temp.substr(a-n)==part){
                temp=temp.substr(0,a-n);
            }
        }return temp;
    }
};