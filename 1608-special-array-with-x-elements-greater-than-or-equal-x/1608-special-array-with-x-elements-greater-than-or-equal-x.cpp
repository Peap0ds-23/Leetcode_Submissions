class Solution {
public:
    int specialArray(vector<int>& nums) {
        int x=nums.size();
        while(x>0){
            int p=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=x){
                    p++;
                }
            }
            if(p==x){
                return x;
            }
            x--;
        }return -1;
        
    }
};