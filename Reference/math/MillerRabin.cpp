// Primality Tests for Large Number
// Complexity: O(k * log(n)^3)
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