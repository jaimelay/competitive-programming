#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

struct SegmentTree {
    struct Node {
        vector<int> v;
    };

    int size;
    vector<Node> nodes;

    Node merge(Node a, Node b) {
        vector<int> v1 = a.v, v2 = b.v, v3(v1.size() + v2.size());
        std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
        return { v3 };
    }

    SegmentTree(int n, vector<int> &v) {
        size = n;
        nodes.resize(4 * n);
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int ptr, int left, int right) {
        if (right == left) {
            if (left < (int) v.size()) {
                nodes[ptr].v.push_back(v[left]);
            }
        } else {
            int mid = (right + left) / 2;

            build(v, 2 * ptr + 1, left, mid);
            build(v, 2 * ptr + 2, mid + 1, right);

            nodes[ptr] = merge(nodes[2 * ptr + 1], nodes[2 * ptr + 2]);
        }
    }

    int query(int l, int r, int ptr, int left, int right, int k) {
        if (left >= l && right <= r) {
            return nodes[ptr].v.size() - (lower_bound(nodes[ptr].v.begin(), nodes[ptr].v.end(), k) - nodes[ptr].v.begin());
        }

        int mid = (right + left) / 2;

        if (r <= mid) {
            return query(l, r, 2 * ptr + 1, left, mid, k);
        } else if (l > mid) {
            return query(l, r, 2 * ptr + 2, mid + 1, right, k);
        } else {
            int qry1 = query(l, r, 2 * ptr + 1, left, mid, k);
            int qry2 = query(l, r, 2 * ptr + 2, mid + 1, right, k);
            return qry1 + qry2;
        }
    }

    int query(int l, int r, int k) {
        return query(l, r, 0, 0, size, k);
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    SegmentTree st(n, v);

    while (q--) {
        int l, k, r;
        cin >> l >> k >> r;

        if (k <= v[l - 1] || r == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << st.query(l, (l + r) - 1, k) << endl;
    }

    return 0;
}