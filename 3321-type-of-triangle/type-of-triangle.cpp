class Solution {
public:
    string triangleType(vector<int>& nums) {
        vector<int> arr(101,0);
        string ans="scalene";
        for(int i=0;i<3;i++){
            arr[nums[i]]++;
            if(arr[nums[i]]==2){
                ans="isosceles"; 
            }
            if(arr[nums[i]]==3){
                ans="equilateral"; 
            }
        }
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2]){
            ans="none";
        }
        return ans;
    }
};