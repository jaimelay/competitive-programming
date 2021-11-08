#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

long long fib[75], factors[10000], nf;

void buildFibonacci() {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 75; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

bool solve(long long n, long long k) {
    if (n == 1) {
        return true;
    }

    while (k > 2) {
        while (n < fib[k]) {
            k--;
        }

        if (n % fib[k] == 0) {
            factors[++nf] = k;
            n = n / fib[k];

            if (solve(n, k)) {
                return true;
            }

            n = n * fib[k];
            nf--;
        }

        k--;
    }

    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    buildFibonacci();

    long long n;
    cin >> n;

    nf = 0;

    solve(n, 75);

    if (nf > 0) {
        string ans;

        for (int i = 1; i <= nf; i++) {
            for (int j = 1; j <= factors[i] - 2; j++) {
                ans += "A";
            }
            ans += "B";
        }

        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}