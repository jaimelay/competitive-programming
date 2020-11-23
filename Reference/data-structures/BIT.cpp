// Fenwick Tree | Binary Indexed Tree
// Complexity:- update: O(log(n)); query: O(log(n))
struct BIT {
    vector<int> tree;
    int LOGN = 25;
    int n;

    BIT(int n) : n(n) {
        tree.resize(n);
        LOGN = (int)ceil(log2(n));
    }

    void update(int idx, int val) {
        for (int i = idx; i <= n; i += (i & -i)) {
            tree[i] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        
        for (int i = idx; i > 0; i -= (i & -i)) {
            sum += tree[i];
        }

        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int lowerBound(int val) {
        int sum = 0, pos = 0;

        for (int i = LOGN; i >= 0; i--) {
            if (pos + (1 << i) < n and sum + tree[pos + (1 << i)] < val) {
                sum += tree[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};