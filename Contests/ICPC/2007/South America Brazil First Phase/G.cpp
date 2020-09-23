#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 100010;

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

    int query(int l, int r, int ptr, int left, int right) {
        if (right < l || left > r) {
            return -1;
        }

        if (nodes[ptr].val != 0) {
            return -1;
        }

        if (right == left) {
            return { left };
        }

        int mid = (right + left) / 2;

        int s = query(l, r, 2 * ptr + 1, left, mid);

        if (s == -1) {
            s = query(l, r, 2 * ptr + 2, mid + 1, right);
        }

        return s;
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<int> trocas(m);
        for (auto &x : trocas) cin >> x;

        vector<int> ans(n, 0);
        SegmentTree segtree(n, ans);

        int cnt = 1;

        for (int i = 0; i < m; i++) {
            if (ans[trocas[i]] != 0) {
                int idx = segtree.query(trocas[i], n);
                ans[idx] = cnt;
                segtree.update(idx, cnt++);
            } else {
                ans[trocas[i]] = cnt;
                segtree.update(trocas[i], cnt++);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) ans[i] = cnt++;
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}