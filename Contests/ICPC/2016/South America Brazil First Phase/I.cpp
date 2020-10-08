#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int ans = 0;

    v[0] = 1;
    v[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        v[i] = min(v[i], v[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; i--) {
        v[i] = min(v[i], v[i + 1] + 1);
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i]);
    }

    cout << ans << endl;

    return 0;
}