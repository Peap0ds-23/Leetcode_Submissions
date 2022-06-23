class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int arr[101];
        vector <int> vec;
        for(int i=0;i<101;i++){
            arr[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            
        }
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=0;j<nums[i];j++){
                sum+=arr[j];
            }
            vec.push_back(sum);
        }
        return vec;
        
    }
};