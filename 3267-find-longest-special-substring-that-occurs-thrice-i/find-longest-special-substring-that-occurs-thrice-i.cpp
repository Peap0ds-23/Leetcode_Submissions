class Solution {
public:
    int maximumLength(string s) {
        map<string,int> m;
        for(int n=s.size()-2;n>0;n--){
            for(int i=0;i<=s.size()-n;i++){
                // m.insert({s.substring(i,n),})
                string str=s.substr(i,n);
                bool flag=false;
                for(int j=1;j<str.size();j++){
                    if(str[j]!=str[0]){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    m[s.substr(i,n)]++;
                    if(m[s.substr(i,n)]==3){
                        return n;
                    }
                }
                
            }
            m.clear();
        } return -1;
    }
};