struct SegmentTreeLazy {
    struct Node {
        long long val;
    };

    int size;
    vector<Node> nodes, lazy;

    SegmentTreeLazy(int n, vector<long long> &v) {
        size = n;
        nodes.resize(4 * n);
        lazy.resize(4 * n, { -1 });
        build(v, 0, 0, size);
    }

    Node merge(Node a, Node b) {
        return { (a.val + b.val) };
    }

    Node single(long long v) {
        return { v };
    }

    void build(vector<long long> &v, int ptr, int left, int right){
        if (right == left) {
            if (left < (int) v.size()) {
                nodes[ptr] = single(v[left]);
            }
        } else {
            int mid = (right + left) / 2;

            build(v, 2 * ptr + 1, left, mid);
            build(v, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2*ptr + 2]);
        }
    }

    void propagate(int ptr, int left, int right){
        if (lazy[ptr].val != -1) {
            nodes[ptr].val = (right - left + 1) * lazy[ptr].val; // RSQ = (right - left + 1) * lazy[ptr].val

            if (left != right) {
                lazy[2 * ptr + 1].val = lazy[ptr].val;
                lazy[2 * ptr + 2].val = lazy[ptr].val;
            }

            lazy[ptr].val = -1;
        }
    }

    void update(int l, int r, int val, int ptr, int left, int right){
        propagate(ptr, left, right);

        if (right < l || left > r) {
            return;
        }

        if (left >= l && right <= r) {
            lazy[ptr].val = val;
            propagate(ptr, left, right);
        } else {
            int mid = (right + left) / 2;

            update(l, r, val, 2 * ptr + 1, left, mid);
            update(l, r, val, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
        }
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, size);
    }

    Node query(int l, int r, int ptr, int left, int right){
        propagate(ptr, left, right);

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