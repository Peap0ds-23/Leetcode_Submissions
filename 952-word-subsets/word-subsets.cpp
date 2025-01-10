class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // unordered_map<int,int> m,m1;
        vector<int> m(26,0);
        vector<string> ans;

        for(int j=0;j<words2.size();j++){
            vector<int> m1(26,0);
            for(int i=0;i<words2[j].size();i++){

                char ch=words2[j][i];
                m1[ch-'a']++;
                // m1[j][words2[j][i]-'a']++;
            }
            for(int i=0;i<26;i++){
                m[i]=max(m[i],m1[i]);
            }
        }
        // for(int i=0;i<26;i++){
        //     // for(int j=1;j<=10;j++){
        //     //     for(int k=0;K<)
        //     // }
        //     cout<<char('a'+i) <<m[i]<<endl;
        // }
        for(int i=0;i<words1.size();i++){
            vector<int> m1(26,0);
            for(int j=0;j<words1[i].size();j++){
                m1[words1[i][j]-'a']++;
            }
            bool flag=true;
            for(int j=0;j<26;j++){
                if(m[j]>0 && m1[j]<m[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }

            // for(int j=0;j<words2.size();j++){
            //     for(int k)
            // }
        }
        return ans;
    }
};