class Solution {
public:

    struct Node {
        int prod = 1;
        array<int, 5> cnt{};

        Node() {
            cnt.fill(0);
        }
    };

    int k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {

        Node ans;

        // Product of complete segment
        ans.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int i = 0; i < k; i++) {
            ans.cnt[i] += left.cnt[i];
        }

        // Prefixes = complete left + prefix of right
        for (int i = 0; i < k; i++) {

            if (right.cnt[i] == 0)
                continue;

            int rem = (left.prod * i) % k;

            ans.cnt[rem] += right.cnt[i];
        }

        return ans;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(nums, node << 1, l, mid);
        build(nums, node << 1 | 1, mid + 1, r);

        tree[node] = merge(tree[node << 1],
                           tree[node << 1 | 1]);
    }

    void update(int node, int l, int r,
                int idx, int value) {

        if (l == r) {

            int rem = value % k;

            tree[node].prod = rem;
            tree[node].cnt.fill(0);
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid) {
            update(node << 1, l, mid, idx, value);
        }
        else {
            update(node << 1 | 1, mid + 1, r, idx, value);
        }

        tree[node] = merge(tree[node << 1],
                           tree[node << 1 | 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Complete overlap
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) >> 1;

        // Completely in left
        if (qr <= mid) {
            return query(node << 1, l, mid,
                         ql, qr);
        }

        // Completely in right
        if (ql > mid) {
            return query(node << 1 | 1, mid + 1, r,
                         ql, qr);
        }

        // Query crosses both sides
        Node left = query(node << 1, l, mid,
                          ql, qr);

        Node right = query(node << 1 | 1,
                           mid + 1, r,
                           ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n + 5);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            update(1, 0, n - 1,
                   index, value);

            // Query [start, n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};