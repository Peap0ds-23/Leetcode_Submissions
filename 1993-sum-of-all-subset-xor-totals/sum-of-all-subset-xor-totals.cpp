class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<vector<int>> temp;
        temp.push_back({});
        // int st=0,en=-1;
        for(int i=0;i<n;i++){
            int sz=temp.size();
            // st=0;
            // if(i>0 && nums[i]==nums[i-1]){
            //     st=en+1;    
            // }
            for(int j=0;j<sz;j++){
                vector<int> temp2=temp[j];
                temp2.push_back(nums[i]);
                temp.push_back(temp2);
            }
            // en=sz;

        }
        for(int i=0;i<temp.size();i++){
            int var=0;
            for(int j=0;j<temp[i].size();j++){
                var^=temp[i][j];
            }
            ans+=var;
        }return ans;
    }
};