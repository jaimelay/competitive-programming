// Complexity: O(log(n))
long long gcd(long long a, long long b) { 
    return b ? gcd(b, a % b) : a;
}

// Complexity: O(log(n))
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Complexity: O(log(n))
long long gcde(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        long long d = gcde(b, a % b, y, x);
        y -= x * (a / b);
        return d;
    }
}