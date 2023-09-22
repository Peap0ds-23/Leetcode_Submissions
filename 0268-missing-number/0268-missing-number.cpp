class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,temp,corr;
        while(i<nums.size()){
            corr=nums[i];
            if(corr<nums.size() && nums[i]!=nums[corr]){
                temp=nums[i];
                nums[i]=nums[corr];
                nums[corr]=temp;
            }
            else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }return nums.size();
    }
};