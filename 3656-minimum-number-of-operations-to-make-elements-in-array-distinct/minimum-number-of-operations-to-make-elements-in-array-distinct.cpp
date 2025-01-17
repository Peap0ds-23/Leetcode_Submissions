class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        // unordered_map<int,int> m;
        vector<int> temp(101,0);
        int maxx=n;
        for(int i=n-1;i>=0;i--){
            if(temp[nums[i]]>0){
                maxx=i;
                break;
            }
            temp[nums[i]]++;
        }
        if(maxx==n){
            return 0;
        }
        count=maxx/3;
        // if(maxx%3==0){
            count++;
        // }
        return count;

    }
};