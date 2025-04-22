class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> st; 
        for (int x : nums) {
            int currMax = x;
            while (!st.empty() && st.back() > currMax) {
                currMax = max(currMax, st.back());
                st.pop_back();
            }
            st.push_back(currMax);
        }
        return st.size();
    }
};