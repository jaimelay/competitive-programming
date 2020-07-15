// build: O(n), update: O(log(n)), query: O(log(n))
struct SegmentTree {
    struct Node {
        int val;
    };

    int size;
    vector<Node> nodes;

    Node NEUTRAL_ELEMENT = { INF };

    Node merge(Node a, Node b) {
        return { min(a.val, b.val) };
    }

    Node single(int v) {
        return { v };
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        nodes.resize(2 * size);
    }

    void build(vector<int> &v, int ptr, int left, int right) {
        if (right - left == 1) {
            if (left < (int) v.size()) {
                nodes[ptr] = single(v[left]);
            }
            return;
        }

        int mid = (right + left) / 2;
        build(v, 2 * ptr + 1, left, mid);
        build(v, 2 * ptr + 2, mid, right);
        nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
    }

    void build(vector<int> &v) {
        build(v, 0, 0, size);
    }

    void update(int idx, int val, int ptr, int left, int right) {
        if (right - left == 1) {
            nodes[ptr] = single(val);
            return;
        }

        int mid = (right + left) / 2;
        if (idx < mid) {
            update(idx, val, 2 * ptr + 1, left, mid);
        } else {
            update(idx, val, 2 * ptr + 2, mid, right);
        }
        nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, size);
    }

    Node query(int l, int r, int ptr, int left, int right) {
        if (left >= r || l >= right) {
            return NEUTRAL_ELEMENT;
        }

        if (left >= l && right <= r) {
            return nodes[ptr];
        }

        int mid = (right + left) / 2;
        Node qry1 = query(l, r, 2 * ptr + 1, left, mid);
        Node qry2 = query(l, r, 2 * ptr + 2, mid, right);
        return merge(qry1, qry2);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};