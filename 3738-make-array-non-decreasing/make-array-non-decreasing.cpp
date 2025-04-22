class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> st;  // will hold the segment maxima in non-decreasing order
        for (int x : nums) {
            int currMax = x;
            // Merge with previous segments while we have an inversion
            while (!st.empty() && st.back() > currMax) {
                // Merged segment's maximum is the greater of the two:
                currMax = max(currMax, st.back());
                st.pop_back();
            }
            st.push_back(currMax);
        }
        return st.size();
    }
};