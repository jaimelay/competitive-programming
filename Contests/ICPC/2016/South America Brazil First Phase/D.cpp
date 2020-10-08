#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

set<int> divisors(int n) {
    set<int> st;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                st.insert(i);
            } else {
                st.insert(n / i);
                st.insert(i);
            }
        }
    }

    return st;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    set<int> divisores = divisors(c);
    int ans = -1;

    for (auto x : divisores) {
        if (x % a == 0 && x % b != 0 && d % x != 0) {
            ans = x;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}