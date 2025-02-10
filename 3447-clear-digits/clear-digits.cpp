class Solution {
public:
    string clearDigits(string s) {
        int j=1;
        int n=s.size();
        string temp="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[j]<='z'){
                temp+=s[i];
            }else{
                if(temp.size()>0){
                    temp=temp.substr(0,temp.size()-1);
                }else{
                    temp+=s[i];
                }
            }
        }
        return temp;
        // while(j<n){
        //     if(s[j]>='0' && s[j]<='9' && s[j-1]>='a' && s[j-1]<='z'){
        //         j++;

        //     }
        // }
    }
};