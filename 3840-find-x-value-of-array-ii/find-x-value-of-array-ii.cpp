class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int K, vector<vector<int>>& queries) {
        int N = nums.size();
        if (K == 1) {
            vector<int> ans;
            ans.reserve(queries.size());
            for (auto &q : queries) {
                int start = q[2], x = q[3];
                ans.push_back(x == 0 ? N - start : 0);
            }
            return ans;
        }
        int sz = 1;
        while (sz < N) sz <<= 1;
        struct Node { 
            int prod; 
            int C[25]; 
        };
        vector<Node> seg(2 * sz);
        Node identity;
        identity.prod = 1 % K;
        for (int i = 0; i < K * K; i++) identity.C[i] = 0;
        static int mul[5][5];
        for (int a = 0; a < K; a++)
            for (int b = 0; b < K; b++)
                mul[a][b] = (a * b) % K;
        auto make_leaf = [&](int v_mod) {
            Node leaf;
            leaf.prod = v_mod;
            for (int i = 0; i < K*K; i++) leaf.C[i] = 0;
            for (int a = 0; a < K; a++) {
                int b = mul[a][v_mod];
                leaf.C[a*K + b] = 1;
            }
            return leaf;
        };
        auto merge = [&](const Node &L, const Node &R) {
            Node res;
            res.prod = mul[L.prod][R.prod];
            for (int a = 0; a < K; a++) {
                int base = a * K;
                int mid = mul[a][L.prod];
                for (int b = 0; b < K; b++) {
                    res.C[base + b] = L.C[base + b] + R.C[mid*K + b];
                }
            }
            return res;
        };
        for (int i = 0; i < sz; i++) {
            if (i < N) seg[sz + i] = make_leaf(nums[i] % K);
            else       seg[sz + i] = identity;
        }
        for (int i = sz - 1; i > 0; i--)
            seg[i] = merge(seg[i<<1], seg[i<<1|1]);
        vector<int> ans;
        ans.reserve(queries.size());
        int startState = 1 % K;
        for (auto &q : queries) {
            int idx = q[0], v_mod = q[1] % K, start = q[2], x = q[3];
            int p = sz + idx;
            seg[p] = make_leaf(v_mod);
            for (p >>= 1; p; p >>= 1)
                seg[p] = merge(seg[p<<1], seg[p<<1|1]);
            int l = sz + start, r = sz + N;
            Node left = identity, right = identity;
            while (l < r) {
                if (l & 1) left = merge(left, seg[l++]);
                if (r & 1) right = merge(seg[--r], right);
                l >>= 1; r >>= 1;
            }
            Node res = merge(left, right);
            ans.push_back(res.C[startState * K + x]);
        }
        return ans;
    }
};