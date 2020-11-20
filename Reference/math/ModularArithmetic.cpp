long long addMod(long long a, long long b, long long mod = MOD) {
    return (a + b) % mod;
}

long long subMod(long long a, long long b, long long mod = MOD) {
    return (a - b + mod) % mod;
}

long long inverseMod(long long a, long long mod = MOD) {
    long long x, y;
    long long g = gcde(a, mod, x, y);

    if (g != 1) {
        return -1;
    } else {
        return (x % mod + mod) % mod;
    }
}

long long multMod(long long a, long long b, long long mod = MOD) {
    return (a * b) % mod;
}

long long divMod(long long a, long long b, long long mod = MOD) {
    return multMod(a, inverseMod(b, mod));
}

long long powMod(long long b, long long e, long long mod = MOD) {
	long long p = 1;
	for (; e; b = b * b % mod, e /= 2) {
		if (e & 1) {
            p = p * b % mod;
        }
    }
	return p;
}

// to avoid long long overflow and increase speed of mult and pow use the functions below.
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