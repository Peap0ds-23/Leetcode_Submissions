class Solution {
public:
    bool hasMatch(string s, string p) {
        int n=s.size();
        int temp=-1;
        for(int i=0;i<p.size();i++){
            if(p[i]=='*'){
                temp=i;
                break;
            }
        }
        string left=p.substr(0,temp);
        string right=p.substr(temp+1);
        int leftIndex=s.find(left);
        if(leftIndex!=-1){
            if(s.substr(leftIndex+temp).find(right)!=-1){
                return true;
            }
        }
        return false;
    }
};