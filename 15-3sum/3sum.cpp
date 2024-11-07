class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int target;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]){
                target=-nums[i];
            }else{
                target=nums[i];
            }
            int st=i+1,en=nums.size()-1;
            while(st<en){
                if(nums[st]+nums[en]>target){
                    en--;
                }else if(nums[st]+nums[en]<target){
                    st++;
                }else{
                    vector<int> v={nums[i],nums[st],nums[en]};
                    ans.push_back(v);
                    while(en>0 && nums[en-1]==nums[en]){
                        en--;
                    }
                    while(st<nums.size()-1 && nums[st+1]==nums[st]){
                        st++;
                    }
                    en--;
                    st++;
                }
            }
            
        }return ans;
    }
};