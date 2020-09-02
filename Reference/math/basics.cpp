long long gcd(long long a, long long b) { 
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long gcde(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    } else {
        long long d = gcde(b, a % b, y, x);

        y -= a / b * x;

        return d;
    }
}

long long multMod(long long a, long long b, long long mod = MOD) {
    long long result = 0;

    while (b) {
        if (b & 1) {
            result = (result + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }

    return result;
}

long long addMod(long long x, long long c, long long mod = MOD) {
    return (x + c) % mod;
}

long long inverseMod(long long a, long long mod = MOD) {
    long long x, y;
    long long g = gcde(a, mod, x, y);

    if (g != 1) {
        return -1;
    } else {
        x = (x % mod + mod) % mod;
        
        return x;
    }
}

long long chinese_remainder(vector<pair<long long, long long>> v) {
    long long rem = v[0].first, mod = v[0].second;
    long long ans = rem, m = mod;

    for (int i = 1; i < (int)v.size(); i++) {
        long long x, y;
        rem = v[i].first, mod = v[i].second;
        long long g = gcde(mod, m, x, y);

        if ((ans - rem) % g != 0) {
            return -1;
        }

        ans = ans + 1LL * (rem - ans) * (m / g) * y;
        m = (mod / g) * (m / g) * g;
        ans = (ans % m + m) % m;
    }

    if (ans == 0) {
        long long _lcm = v[0].second;

        for (int i = 1; i < (int)v.size(); i++) {
            _lcm = lcm(_lcm, v[i].second);
        }

        return _lcm;
    }

    return ans;
}