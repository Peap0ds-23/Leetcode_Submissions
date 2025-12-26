class Solution {
public:
    string getKey(const vector<int>& v) {
        string s;
        for (int x : v) {
            s += to_string(x);
            s.push_back(',');
        }
        return s;
    }

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;

        unordered_set<string> visited;
        queue<pair<vector<int>, int>> q;

        visited.insert(getKey(nums1));
        q.push({nums1, 0});

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            int n = cur.size();

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {

                    vector<int> other, mid;

                    for (int k = 0; k < i; k++)
                        other.push_back(cur[k]);

                    for (int k = i; k <= j; k++)
                        mid.push_back(cur[k]);

                    for (int k = j + 1; k < n; k++)
                        other.push_back(cur[k]);

                    int len = other.size();

                    for (int pos = 0; pos <= len; pos++) {
                        vector<int> temp;

                        for (int k = 0; k < pos; k++)
                            temp.push_back(other[k]);

                        for (int k = 0; k < mid.size(); k++)
                            temp.push_back(mid[k]);

                        for (int k = pos; k < len; k++)
                            temp.push_back(other[k]);

                        if (temp == nums2)
                            return steps + 1;

                        string key = getKey(temp);
                        if (!visited.count(key)) {
                            visited.insert(key);
                            q.push({temp, steps + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};