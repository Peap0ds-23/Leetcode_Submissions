class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0LL);
        vector<long long> dp_prev(k, 0LL), dp_cur(k, 0LL);

        for (int i = 0; i < n; i++) {
            int ai = nums[i] % k;
            for (int m = 0; m < k; m++) dp_cur[m] = 0;
            for (int m = 0; m < k; m++) {
                if (dp_prev[m] > 0) {
                    int nm = (int)((1LL * m * ai) % k);
                    dp_cur[nm] += dp_prev[m];
                }
            }
            dp_cur[ai] += 1;
            for (int x = 0; x < k; x++) {
                result[x] += dp_cur[x];
            }
            dp_prev.swap(dp_cur);
        }

        return result;
    }
};
