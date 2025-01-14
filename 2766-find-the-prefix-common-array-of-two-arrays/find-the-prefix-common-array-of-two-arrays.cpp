class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;
        unordered_map<int,int> m;
        int temp=0;
        for(int i=0;i<n;i++){
            m[A[i]]++;
            m[B[i]]++;
            if(m[A[i]]==2){
                temp++;
                m.erase(A[i]);
            }
            if(m[B[i]]==2){
                temp++;
                m.erase(B[i]);
            }
            // temp=0;
            // for(auto it:m){
            //     int ind=it.first;
            //     int val=it.second;
            //     if(val==2){
            //         temp++;
            //     }
            // }
            ans.push_back(temp);
        }return ans;
    }
};