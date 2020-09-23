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

    int n, l;

    while (cin >> n >> l) {
        if (n == 0 || l == 0) {
            break;
        }
        
        vector<int> v(l);
        for (auto &x : v) cin >> x;

        int i = 0, j = 0;
        int best_range = 0;
        
        while (best_range < n && j < l) {
            if (v[j] <= v[i] + n - 1) {
                best_range = max(best_range, j - i + 1);
                j++;
            } else {
                i++;
            }
        }

        cout << n - best_range << endl;
    }

    return 0;
}