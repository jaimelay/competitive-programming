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

    int c;

    cin >> c;

    int cnt = 100, ans = 100;

    for (int i = 0, x; i < c; i++) {
        cin >> x;
        
        cnt += x;
        
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}