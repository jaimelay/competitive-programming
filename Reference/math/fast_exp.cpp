const long long mod = 1e9+7;

long long fast_exp(long long a, long long b){
    long long result = 1;
    while(b){
        if(b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}