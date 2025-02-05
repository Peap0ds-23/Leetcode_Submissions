class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // int a=-1,b=-1;
        vector<char> a;
        vector<char> b;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                // a=i;
                a.push_back(s1[i]);
                b.push_back(s2[i]);
            }
        }
        if(a.size()>2 || a.size()==1){
            return false;
        }
        // reverse(a.begin())
        if(a.size()==2 && (a[0]!=b[1] || a[1]!=b[0])){
            return false;
        }return true;
    }
};