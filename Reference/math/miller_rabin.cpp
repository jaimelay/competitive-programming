// Primality Tests
// Complexity: O(k * log(n)^3)

bool isComposite(long long n, long long a, long long d, int s) {
    long long x = fast_exp(a, d, n);

    if (x == 1 || x == n - 1) {
        return false;
    }

    for (int r = 1; r < s; r++) {
        x = multMod(x, x, n);

        if (x == n - 1) {
            return false;
        }
    }

    return true;
};

bool millerRabin(long long n) {
    if (n < 2) {
        return false;
    }

    int r = 0;
    long long d = n - 1;

    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
        if (n == a) {
            return true;
        }

        if (isComposite(n, a, d, r)) {
            return false;
        }
    }

    return true;
}