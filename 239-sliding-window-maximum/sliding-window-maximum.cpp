class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> temp;
        int j=0,n=nums.size(),i=0;
        while(j<n){
            while(temp.size()>0 && temp.back()<nums[j]){
                temp.pop_back();
            }
            temp.push_back(nums[j]);
            if((j-i+1)<k){
                j++;
            }else if((j-i+1)==k){
                ans.push_back(temp.front());
                if(nums[i]==temp.front()){
                    temp.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};