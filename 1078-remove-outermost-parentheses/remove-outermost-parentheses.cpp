class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int count=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(count==0 && s[i]=='('){
                count++;
            }else if(count==1 && s[i]==')'){
                count--;
            }else if(s[i]=='('){
                count++;
                ans+=s[i];
            }else{
                count--;
                ans+=s[i];
            }
        }return ans;
    }
};