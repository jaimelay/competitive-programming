const long long mod = 1e9+7;

typedef vector<vector<long long>> matrix;
long long mat_size;

matrix mult(matrix a, matrix b){
    matrix c(mat_size, vector<long long>(mat_size));
    for(int i = 0; i < mat_size; i++)
        for(int j = 0; j < mat_size; j++)
            for(int k = 0; k < mat_size; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c;
}

matrix pow(matrix base, long long n){
    if(n == 1) return base;
    if(n & 1) return mult(base, pow(base, n - 1));
    matrix tmp = pow(base, n/2);
    return mult(tmp, tmp);
}