class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> m;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i]-i;
            if(m.find(temp)!=m.end()){
                count+=m[temp];
            }
            m[temp]++;
        }
        int n=nums.size();
        long long total=n;
        total*=(n-1);
        total/=2;
        
        total-=count;
        return total;
    }
};