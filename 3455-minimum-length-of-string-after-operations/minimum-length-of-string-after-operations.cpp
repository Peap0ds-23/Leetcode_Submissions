class Solution {
public:
    int minimumLength(string s) {
        vector<int> temp(26,0);
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(temp[i]<3){
                count+=temp[i];
            }else{
                while(temp[i]>=3){
                    temp[i]-=2;
                }
                count+=temp[i];
            }
        }return count;
    }
};