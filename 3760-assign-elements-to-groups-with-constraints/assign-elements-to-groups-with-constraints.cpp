class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        map<int,int> m;
        for(int i=0;i<elements.size();i++){
            if(m.find(elements[i])==m.end()){
                m[elements[i]]=i;
            }
        }
        vector<int> ans;
        for(int i=0;i<groups.size();i++){
            int a=groups[i];
            int st=1;
            int en=sqrt(a);
            int minn=INT_MAX;
            for(int j=st;j<=en;j++){
                if(a%j==0){
                    if(m.find(j)!=m.end()){
                        minn=min(minn,m[j]);
                    }
                    if(m.find(a/j)!=m.end()){
                        minn=min(minn,m[a/j]);
                    }
                }
            }
            if(minn==INT_MAX){
                ans.push_back(-1);
            }else{
                ans.push_back(minn);
            }

        }return ans;
    }
};