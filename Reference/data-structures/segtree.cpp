// build: O(n), update: O(log(n)), query: O(log(n))
// 0-indexed, query in the closed interval [l, r].
struct SegmentTree {
    struct Node {
        long long val;
    };

    int size;
    vector<Node> nodes;

    Node merge(Node a, Node b) {
        return { min(a.val, b.val) };
    }

    Node single(int v) {
        return { v };
    }

    SegmentTree(int n, vector<int> &v) {
        size = n;
        nodes.resize(4 * n);
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int ptr, int left, int right) {
        if (right == left) {
            if (left < (int) v.size()) {
                nodes[ptr] = single(v[left]);
            }
        } else {
            int mid = (right + left) / 2;

            build(v, 2 * ptr + 1, left, mid);
            build(v, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
        }
    }

    void update(int idx, int val, int ptr, int left, int right) {
        if (right == left) {
            nodes[ptr] = single(val);
        } else {
            int mid = (right + left) / 2;

            if (idx <= mid) {
                update(idx, val, 2 * ptr + 1, left, mid);
            } else {
                update(idx, val, 2 * ptr + 2, mid + 1, right);
            }

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
        }
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, size);
    }

    Node query(int l, int r, int ptr, int left, int right) {
        if (left >= l && right <= r) {
            return nodes[ptr];
        }

        int mid = (right + left) / 2;

        if (r <= mid) {
            return query(l, r, 2 * ptr + 1, left, mid);
        } else if (l > mid) {
            return query(l, r, 2 * ptr + 2, mid + 1, right);
        } else {
            Node qry1 = query(l, r, 2 * ptr + 1, left, mid);
            Node qry2 = query(l, r, 2 * ptr + 2, mid + 1, right);
            return merge(qry1, qry2);
        }
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};