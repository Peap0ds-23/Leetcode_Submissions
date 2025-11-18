class Solution {
public:
    int maxPower(string s) {
        int len=1,count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
                len=max(len,count);
            }else{
                count=1;
            }
        }return len;
    }
};