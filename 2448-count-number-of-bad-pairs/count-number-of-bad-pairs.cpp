class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long n=nums.size();
        long long count=(n*(n-1))/2;
        m[nums[0]]++;
        for(int i=1;i<n;i++){
            int temp=nums[i]-i;
            if(m.find(temp)!=m.end()){
                count-=(m[temp]);
            }
            m[temp]++;
        }return count;
    }
};