#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, d, m;
    cin >> t >> d >> m;

    vector<int> v;
    v.push_back(0);
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        v.push_back(x);
    }
    v.push_back(d);

    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] - v[i - 1] >= t) {
            cout << "Y" << endl;
            return 0;
        }
    }

    cout << "N" << endl;

    return 0;
}