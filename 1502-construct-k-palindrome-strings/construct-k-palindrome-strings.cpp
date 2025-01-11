class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k>n){
            return false;
        }
        if(k==n){
            return true;
        }
        vector<int> arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int odd=0,even=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2){
                odd++;
                even+=(arr[i]/2);
            }else{
                even+=(arr[i]/2);
            }
        }
        if(odd>k){
            return false;
        }
        if(odd==k){
            return true;
        }
        k-=odd;
        if(k<=2*even){
            return true;
        }return false;
    }
};