// Prime factors using sieve (precomputed primes). (up to 9*10^14. For greater see Pollard Rho)

vector<long long> factorization(long long n) {
    vector<long long> factorization;

    for (long long d : primes) {
        if (d * d > n) {
            break;
        }

        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    if (n > 1) {
        factorization.push_back(n);
    }
    
    return factorization;
}