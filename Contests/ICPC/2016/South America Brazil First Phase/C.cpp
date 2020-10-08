#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

struct Container {
    vector<int> v;
    int cost;

    Container(vector<int> &a, int c) : v(a), cost(c) {}
};

struct Comparator {
    bool operator () (Container &a, Container &b) {
        return a.cost > b.cost;
    }
};

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

bool isEqual(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < 8; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void solve(int a, int b, Container ct, priority_queue<Container, vector<Container>, Comparator> &pq, unordered_set<vector<int>, VectorHash> &vis) {
    swap(ct.v[a], ct.v[b]);
    ct.cost += ct.v[a] + ct.v[b];

    if (vis.find(ct.v) == vis.end()) {
        pq.push(ct);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> s, t;

    for (int i = 0, x; i < 8; i++) {
        cin >> x;
        s.push_back(x);
    }

    for (int i = 0, x; i < 8; i++) {
        cin >> x;
        t.push_back(x);
    }

    priority_queue<Container, vector<Container>, Comparator> pq;
    unordered_set<vector<int>, VectorHash> vis;

    Container start = Container(s, 0);

    pq.push(start);

    while (!pq.empty()) {
        Container u = pq.top();
        pq.pop();

        if (vis.find(u.v) != vis.end()) {
            continue;
        }

        vis.insert(u.v);

        if (isEqual(u.v, t)) {
            cout << u.cost << endl;
            break;
        }

        solve(0, 1, u, pq, vis);
        solve(1, 2, u, pq, vis);
        solve(2, 3, u, pq, vis);

        solve(4, 5, u, pq, vis);
        solve(5, 6, u, pq, vis);
        solve(6, 7, u, pq, vis);

        solve(0, 4, u, pq, vis);
        solve(1, 5, u, pq, vis);
        solve(2, 6, u, pq, vis);
        solve(3, 7, u, pq, vis);
    }

    return 0;
}