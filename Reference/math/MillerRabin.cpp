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