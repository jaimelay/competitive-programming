struct SparseTable {
    int n;
    vector<vector<int>> table;

    SparseTable(vector<int> &v) {
        n = (int)v.size();
        int max_log = 32 - __builtin_clz(n);
        table.resize(max_log);
        table[0] = v;
        
        for (int lg = 1; lg < max_log; lg++) {
            table[lg].resize(n - (1 << lg) + 1);
            for (int i = 0; i <= n - (1 << lg); i++) {
                table[lg][i] = min(table[lg - 1][i], table[lg - 1][i + (1 << (lg - 1))]);
            }
        }
    }

    int getRMQ(int left, int right) {
        assert(0 <= left && left <= right && right <= n - 1);
        int lg = 32 - __builtin_clz(right - left + 1) - 1;
        return min(table[lg][left], table[lg][right - (1 << lg) + 1]);
    }
};