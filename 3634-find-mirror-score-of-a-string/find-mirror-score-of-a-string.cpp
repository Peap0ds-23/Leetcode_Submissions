class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        map<int,vector<int>> m;
        long long count=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            int num=25-(s[i]-'a');
            if(m.find(num)!=m.end()){
                temp.clear();
                temp=m[num];
                int leng=temp.size();
                count+=(i-temp[leng-1]);
                if(leng==1){
                    m.erase(num);
                }else{
                    temp.erase(temp.end()-1);
                    m[num]=temp;
                }
            }else{
                m[s[i]-'a'].push_back(i);
            }
        }return count;
    }
};