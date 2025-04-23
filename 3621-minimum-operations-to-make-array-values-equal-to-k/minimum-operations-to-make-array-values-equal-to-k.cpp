class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0,minn=101,n=nums.size();
        bool flag=false;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            minn=min(minn,nums[i]);
            if(nums[i]==k){
                flag=true;
            }
            s.insert(nums[i]);
        }
        if(k>minn){
            return -1;
        }
        if(flag){
            return s.size()-1;
        }else{
            return s.size();
        }
    }
};