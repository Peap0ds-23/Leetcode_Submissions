class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> temp(n,0);
        vector<int> ans(queries.size(),0);
        int sum=0;
        for(int i=0;i<n;i++){
            int left=words[i][0];
            int right=words[i][words[i].size()-1];
            if(left=='a'|| left=='e' || left=='i' || left=='o' || left=='u'){
                if(right=='a'|| right=='e' || right=='i' || right=='o' || right=='u'){
                    sum++;
                }
            }
            temp[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=temp[queries[i][1]]- temp[queries[i][0]];
            int var=words[queries[i][0]][0];
            int var2=words[queries[i][0]][(words[queries[i][0]]).size()-1];
            if(var=='a'|| var=='e' || var=='i' || var=='o' || var=='u'){
                if(var2=='a'|| var2=='e' || var2=='i' || var2=='o' || var2=='u'){
                    ans[i]++;
                }
                
            }
        }return ans;
    }
};