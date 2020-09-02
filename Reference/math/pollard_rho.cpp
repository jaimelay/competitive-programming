// Integer Factorization For Large Numbers
// Complexity: O(n^1/4)

long long rho(long long n) {
    long long x, y, d, c = 1;

    if (n % 2 == 0) {
        return 2;
    }

    while (true) {
        x = y = 2;

        while (true) {
            x = addmod(multmod(x, x, n), c, n);
            y = addmod(multmod(y, y, n), c, n);
            y = addmod(multmod(y, y, n), c, n);
            d = gcd(abs(x - y), n);

            if (d == n) {
                break;
            } else if (d > 1) {
                return d;
            }
        }
        
        c++;
    }

    return d;
}

void factorization(long long n, vector<long long> &factors) {
    if (n == 1 || millerRabin(n)) {
        return factors.push_back(n);
    }

    long long f = rho(n);
    factorization(f, factors);
    factorization(n / f, factors);
}