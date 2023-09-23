class Solution {
public:
    int myAtoi(string s) {
        s=fun("",s,false,false);
        bool sign=true;
        if(s[0]=='-'){
            sign=false;
            s=s.substr(1);
        }else if(s[0]=='+'){
            s=s.substr(1);
        }
        int n=s.size()-1,ans=0;
        
        for(int i=n;i>=0;i--){
            if(sign && ans+(int)(s[n-i]-'0')*pow(10,i)>INT_MAX){
                ans=INT_MAX;
                return ans;
            }
            if(!sign && -(ans+(int)(s[n-i]-'0')*pow(10,i))<=INT_MIN){
                ans=INT_MIN;
                return ans;
            }
            ans+=(int)(s[n-i]-'0')*pow(10,i);
        }
        if(!sign){
            ans*=(-1);
        }
        return ans;
    }

    string fun(string p,string up,bool flag,bool flag2){
        if(up.size()==0){
            return p;
        }
        char ch=up[0];
        if(!flag && !flag2 && ch==' '){
            return fun(p,up.substr(1),flag,flag2);
        }else if(!flag && !flag2 && (ch=='+' || ch=='-')){
            flag=true;
            return fun(ch+p,up.substr(1),flag,flag2);
        }else if(ch>='0' && ch<='9'){
            flag2=true;
            return fun(p+ch,up.substr(1),flag,flag2);
        }else{
            return p;
        }
    }
};

// very crucial testcasses
// "cdscd5"
// "  +cdcdc"
// "--"
// "+1c23"
// "+123+"
// ""
// "00000-42a1234"
// "  +  413"