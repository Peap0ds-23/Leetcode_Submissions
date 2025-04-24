class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s,s1;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int count=0;
        int sz=s.size();
        for(int i=0;i<n;i++){
            s1.clear();
            for(int j=i;j<n;j++){
                s1.insert(nums[j]);
                if(s1.size()==sz){
                    count++;
                }
            }
        }return count;
    }
};