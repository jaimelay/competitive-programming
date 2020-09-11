typedef vector<vector<long long>> matrix;

matrix matrixMultiplication(matrix a, matrix b){
    matrix c(int(a.size()), vector<long long>(int(b[0].size())));

    for (int i = 0; i < int(a.size()); i++) {
        for (int j = 0; j < int(b[0].size()); j++) {
            for (int k = 0; k < int(b.size()); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
            }
        }
    }

    return c;
}

matrix matrixExponentiation(matrix base, long long n){
    if (n == 1) {
        return base;
    }

    if (n & 1) {
        return matrixMultiplication(base, matrixExponentiation(base, n - 1));
    }

    matrix tmp = matrixExponentiation(base, n / 2);
    
    return matrixMultiplication(tmp, tmp);
}