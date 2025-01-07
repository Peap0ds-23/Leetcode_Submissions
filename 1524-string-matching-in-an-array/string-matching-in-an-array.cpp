class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].find(words[j])!=-1){
                    if(st.find(words[j])==st.end()){
                        st.insert(words[j]);
                        ans.push_back(words[j]);
                    }
                }else if(words[j].find(words[i])!=-1){
                    if(st.find(words[i])==st.end()){
                        st.insert(words[i]);
                        ans.push_back(words[i]);
                    }

                }
            }
        }

        return ans;
    }
};