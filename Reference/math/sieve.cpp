// Complexity: O(n * log(log(n)))

int is_prime[MAXN];
vector<int> primes;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}