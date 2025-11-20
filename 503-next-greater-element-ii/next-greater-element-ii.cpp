class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        // int last=nums[n-1];
        // for(int i=0;i<n;i++){
        //     if(nums[i]>last){
        //         last=nums[i];
        //         break;
        //     }
        // }
        vector<int> ans;
        // ans.push_back(last);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        // st.push(last);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
            }else{
                if(st.top()>nums[i]){
                    ans.push_back(st.top());
                }else{
                    while(!st.empty() && st.top()<=nums[i]){
                        st.pop();

                    }
                    if(st.empty()){
                        ans.push_back(-1);
                    }else{
                        ans.push_back(st.top());
                    }
                }
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};