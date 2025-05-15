class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<string> ans1,ans2;
        int i=0,temp1=0,temp2=1,len1=0,len2=0;
        while(i<n){
            if(groups[i]==temp1){
                temp1=!temp1;
                len1++;
                // 
                ans1.push_back(words[i]);
            }
            if(groups[i]==temp2){
                temp2=!temp2;//0,
                len2++;
                ans2.push_back(words[i]);//c
            }
            i++;
        }
        if(len1>len2){
            return ans1;
        }return ans2;

    }
};