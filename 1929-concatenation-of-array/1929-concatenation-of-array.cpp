class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int> arr;
        int a=nums.size();
        for(int i=0;i<a;i++){
            // arr.insert(i,nums[i]);
            // arr.insert(n+i,nums[i]);
            nums.push_back(nums[i]);
        }
        return nums;
    }
};