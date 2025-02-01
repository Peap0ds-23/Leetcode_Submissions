class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            int count=1;
            int j=1;
            while(s.find(nums[i]-j)!=s.end()){
                s.erase(nums[i]-j);
                count++;
                j++;
            }
            j=1;
            while(s.find(nums[i]+j)!=s.end()){
                s.erase(nums[i]+j);
                count++;
                j++;
            }
            maxx=max(maxx,count);
        }return maxx;
    }
};