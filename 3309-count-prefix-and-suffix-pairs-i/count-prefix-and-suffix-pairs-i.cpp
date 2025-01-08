class Solution {
public:
    bool func(string str1,string str2){
        int len1=str1.size();
        int len2=str2.size();
        if(len1>len2){
            return false;
        }
        if(str2.find(str1)==0){
            string temp=str2.substr(len2-len1);
            if(temp.find(str1)==0){
                return true;
            }
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(func(words[i],words[j])){
                    count++;
                }
            }
        }return count;
    }
};