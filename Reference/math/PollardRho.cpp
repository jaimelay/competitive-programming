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