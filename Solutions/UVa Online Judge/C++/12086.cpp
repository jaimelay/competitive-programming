#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << (#x) << " == " << x << endl;
#define endl '\n'

typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.);
const int MOD = 1e9+7;

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

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int ct = 0;
    vector<int> a;
    while(cin >> n){
        if(n == 0) break;
        else if(ct > 0) cout << endl;
        a.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        BIT b(a, n);
        string action;
        int x, y;
        cout << "Case " << ++ct << ":" << endl;
        while(cin >> action){
            b.print();
            cout << "Valores de A" << endl;
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
            if(action == "END"){
                break;
            }else{
                cin >> x >> y;
                if(action == "S"){
                    b.update(x, y-a[x]);
                    a[x] = y;
                }else if(action == "M"){
                    cout << b.query(x, y) << endl;
                }
            }
        }
    }
    return 0;
}