// Complexity: O(n * log(log(n)))
vector<long long> sieve(int n = 10'000'000) {
    vector<long long> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false, is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}