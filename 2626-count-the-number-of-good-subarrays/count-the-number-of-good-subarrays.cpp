class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> freq;
        long long count = 0;
        int j = 0, n = nums.size();

        for (int i = 0; i < n; ++i) {
            count += freq[nums[i]];
            freq[nums[i]]++;

            while (count >= k) {
                ans += (n - i);
                freq[nums[j]]--;
                count -= freq[nums[j]];
                j++;
            }
        }

        return ans;
    }
};
