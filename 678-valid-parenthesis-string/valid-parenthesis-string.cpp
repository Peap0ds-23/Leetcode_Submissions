class Solution {
public:
    bool checkValidString(string s) {
        int minn=0,maxx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                minn++;
                maxx++;
            }else if(s[i]==')'){
                minn--;
                maxx--;
            }else{
                minn--;
                maxx++;
            }
            if(minn<0){
                minn=0;
            }
            if(maxx<0){
                return false;
            }
        }
        return minn==0;
    }
};