// For number greater than 9*10^14 see Pollard Rho Algorithm.
// Complexity: O(sqrt(n))
vector<long long> getFactors(long long n) {
    vector<long long> factors;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }

    if (n > 1) factors.push_back(n);

    return factors;
}

// Complexity: O(sqrt(n))
vector<long long> getDivisors(long long n) {
    vector<long long> divisors;

    for (long long d = 1 ; d * d <= n; d++) {
        if (n % d == 0) {
            if (n / d == d) divisors.push_back(d);
            else divisors.push_back(d), divisors.push_back(n / d);
        }
    }

    return divisors;
}