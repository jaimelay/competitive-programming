#include <bits/stdc++.h>
 
using namespace std;
 
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "\n{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
 
#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif
 
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
 
typedef unsigned long long ull;
ull multMod(ull a, ull b, ull mod = MOD) {
	long long ret = a * b - mod * ull(1.L / mod * a * b);
	return ret + mod * (ret < 0) - mod * (ret >= (long long)mod);
}
 
ull powMod(ull b, ull e, ull mod = MOD) {
	ull p = 1;
	for (; e; b = multMod(b, b, mod), e /= 2) {
		if (e & 1) {
            p = multMod(p, b, mod);
        }
    }
	return p;
}
 
// Primality Test for Large Number
// Complexity: O(k * log(n)^3)
bool millerRabin(ull n) {
	ull s = __builtin_ctzll(n - 1);
	ull d = n >> s;
	ull base[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
 
	for (ull b : base) {
		ull p = powMod(b % n, d, n);
		ull i = s;
		while (p != 1 && p != n - 1 && b % n && i--) {
			p = multMod(p, p, n);
		}
		if (p != n - 1 && i != s) return false;
	}
 
	return true;
}
 
// Integer Factorization For Large Number
// Complexity: O(n^1/4)
ull pollard(ull n) {
	auto f = [n](ull x) { return multMod(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) {
			x = ++i;
			y = f(x);
		}
		if ((q = multMod(prd, max(x, y) - min(x, y), n))) {
			prd = q;
		}
		x = f(x), y = f(f(y));
	}
	
	return __gcd(prd, n);
}
 
void getFactors(ull n, set<ull> &factors) {
	if (millerRabin(n)) {
		factors.insert(n);
		return;
	}
 
	ull f = pollard(n);
	getFactors(f, factors);
	getFactors(n / f, factors);
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
 
	set<ull> ans;
	for (auto x : v) {
		getFactors(x, ans);
	}
 
	for (auto x : ans) cout << x << " ";
	cout << endl;
 
    return 0;
}