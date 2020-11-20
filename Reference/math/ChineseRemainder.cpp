long long chineseRemainder(vector<pair<long long, long long>> v) {
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