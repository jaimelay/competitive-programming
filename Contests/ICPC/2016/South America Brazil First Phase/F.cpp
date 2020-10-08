#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

struct Node {
    int l;
    int c;
    int r;

    Node() {}
    Node(int l, int c, int r) : l(l), c(c), r(r) {}
};

Node left_tree[10010], right_tree[10010];

int deepest_a = 0, deepest_b = 0;

void calculateDeep(int u, int deep, int &deepest, Node tree[]) {
    if (u == 0) {
        deepest = max(deepest, deep);
        return;
    }

    calculateDeep(tree[u].c, deep + 1, deepest, tree);
    calculateDeep(tree[u].l, 0, deepest, tree);
    calculateDeep(tree[u].r, 0, deepest, tree);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        left_tree[a] = Node(b, c, 0);
    }

    int m;

    cin >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        right_tree[a] = Node(0, b, c);
    }

    calculateDeep(1, 0, deepest_a, left_tree);
    calculateDeep(1, 0, deepest_b, right_tree);

    int rA = 1;
    Node a = left_tree[1];
    
    while (a.c) {
        a = left_tree[a.c];
        rA++;
    }

    int rB = 1;
    Node b = right_tree[1];

    while (b.c) {
        b = right_tree[b.c];
        rB++;
    }

    cout << deepest_a << " " << deepest_b << endl;
    cout << rA << " " << rB << endl;

    cout << n + m - max(min(deepest_a, rB), min(deepest_b, rA)) << endl;

    return 0;
}