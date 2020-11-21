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

    long long n, k, a, b;
    cin >> n >> k;

    vector<long long> weights(n);
    for (auto &x : weights) cin >> x;

    sort(weights.rbegin(), weights.rend());

    cin >> a >> b;

    vector<vector<long long>> comb(55, vector<long long>(55));

    for (int i = 0; i <= 50; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    auto solve = [&](long long x) {
        vector<bool> mask;
        int cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (weights[i] <= x) {
                cnt1++;
                mask.push_back(true);
                x -= weights[i];
            } else {
                mask.push_back(false);
            }
        }

        long long ans = (cnt1 == k);
        cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (mask[i]) {
                if (k - cnt1 >= 0) {
                    ans += comb[n - i - 1][k - cnt1];
                }
                cnt1++;
            }
        }

        return ans;
    };

    cout << solve(b) - solve(a - 1) << endl;

    return 0;
}