#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

// Integer Factorization For Large Numbers
// Complexity: O(n^1/4)
typedef unsigned long long ull;

ull modmul(ull a, ull b, ull M) {
	long long ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (long long)M);
}

ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2) {
		if (e & 1) ans = modmul(ans, b, mod);
    }
	return ans;
}

// Miller-Rabin
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a % n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull rho(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}

vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = rho(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	vector<long long> v(n);
	for (auto &x : v) cin >> x;

	for (int i = 0, a, b, d; i < k; i++) {
		cin >> a >> b >> d;
	}

	set<ull> st;
	for (auto x : v) {
		vector<ull> tmp = factor(x);
		for (auto y : tmp) {
			st.insert(y);
		}
	}

	for (auto x : st) cout << x << " ";
	cout << endl;

    return 0;
}