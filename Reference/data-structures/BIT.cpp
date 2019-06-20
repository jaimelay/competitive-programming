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
        for(int i = 1; i <= n; i++){
            update(i, a[i]);
        }
    }

    void update(int i, int val){
        while(i <= n){
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    int query(int l, int r){
        return query(r) - query(l - 1);
    }
};