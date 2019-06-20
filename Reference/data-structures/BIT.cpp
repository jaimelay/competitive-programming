// Complexidade:- update -> O(logN)
//              - query  -> O(logN)

int a[1000], n;

struct BIT{
    vector<int> bit;
    int n;

    BIT(int n){
        this->n = n;
        bit.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            update(i, a[i]);
        }
    }

    void update(int i, int v){
        for(; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    int query(int i){
        int sum = 0;
        for(; i > 0; i -= i & -i){
            sum += bit[i];
        }
        return sum;
    }

    int query(int l, int r){
        return query(r) - query(l - 1);
    }
}


