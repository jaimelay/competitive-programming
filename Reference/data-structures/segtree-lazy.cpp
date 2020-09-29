struct SegmentTreeLazy {
    struct Node {
        long long val;

        Node(long long val) : val(val) {}
    };

    int size;
    vector<Node> nodes, lazy;

    SegmentTreeLazy(int n, vector<int> &v) {
        size = n;
        nodes.resize(4 * n);
        lazy.resize(4 * n);
        build(v, 0, 0, size);
    }

    Node merge(Node a, Node b) {
        return Node(min(a.val, b.val));
    }

    Node single(long long v) {
        return Node(v);
    }

    void build(vector<int> &v, int ptr, int left, int right){
        if (right == left) {
            nodes[ptr] = single(v[left]);
        } else {
            int mid = (right + left) / 2;

            build(v, 2 * ptr + 1, left, mid);
            build(v, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2*ptr + 2]);
        }
    }

    void propagate(int ptr, int left, int right){
        if (lazy[ptr] != -1) {
            nodes[ptr] = lazy[ptr];  // RMQ  -> update: = lazy[node],                        increment: += lazy[node]
                                    // RSQ  -> update: = (right - left + 1) * lazy[node],   increment: += (right - left + 1) * lazy[node]
            if (left != right) {
                lazy[2 * ptr + 1] = lazy[2 * ptr + 2] = lazy[ptr]; // update: =, increment: +=
            }

            lazy[ptr] = -1;
        }
    }

    void update(int a, int b, int val, int ptr, int left, int right){
        propagate(ptr, left, right);

        if (right < a || left > b) {
            return;
        }

        if (left >= a && right <= b) {
            lazy[ptr] = single(val);
            propagate(ptr, left, right);
        } else {
            int mid = (right + left) / 2;

            update(a, b, val, 2 * ptr + 1, left, mid);
            update(a, b, val, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = nodes[2 * ptr] + nodes[2 * ptr + 1];
        }
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
};