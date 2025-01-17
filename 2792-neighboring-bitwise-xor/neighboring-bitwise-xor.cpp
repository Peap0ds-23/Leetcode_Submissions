class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> temp;
        temp.push_back(0);
        for(int i=0;i<n;i++){
            // if(i<n){
                temp.push_back(derived[i]^temp[i]);
            // }
        }
        if(temp[n]==temp[0]){
            return true;
        }
        temp.clear();
        temp.push_back(1);
        for(int i=0;i<n;i++){
            // if(i<n){
                temp.push_back(derived[i]^temp[i]);
            // }
        }
        if(temp[n]==temp[0]){
            return true;
        }
        return false;
        // [0,1,0,0]
        // a^b=c
        // temp[i]*temp[i+1]=derived[i]
    }
};