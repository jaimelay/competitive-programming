// Complexity: O(n^2)
vector<vector<long long>> binomialCoefficient(int n, int mod = MOD) {
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1));
    C[0][0] = 1;

    for (int i = 1; i <= n; i++){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    return C;
}

// Complexity: O(n)
vector<long long> fact, inv_fact;

void buildBinomial(int n, int mod = MOD) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * 1LL * i) % mod;

    inv_fact[n] = powMod(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = (inv_fact[i + 1] * 1LL * (i + 1)) % mod;
}

long long binomialCoefficient(int n, int k, int mod = MOD) {
    if (n < k) return 0;
    return ((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k] % mod;
}