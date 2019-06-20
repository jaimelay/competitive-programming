// Complexidade:- update -> O(logN)
//              - query  -> O(logN)

vector<int> a, n;

struct BIT{
    vector<int> bit, a;
    long long n;

    BIT(vector<int> &a, long long n){
        this->n = n;
        this->a = a;
        bit.assign(n + 1, 0);
        init();
    }

    void init(){
        for(int i = 1; i <= n; i++)
            update(i, a[i]);
    }

    void update(int x, int val){
        for(int i = x; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int x){
        int sum = 0;
        for(int i = x; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    int query(int l, int r){
        return query(r) - query(l - 1);
    }
};