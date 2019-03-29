#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

struct Digitos{
    ll qntdTres;
    ll qntdZero;
    ll resto;
    int ultimoDigit;
};

ll k;
bool rTres[1000001], rZero[1000001];
queue<Digitos> f;
ll frQntdTres, frQntdZero, frResto, frLastDigit;

ll addThree(ll n){
    string tmp = to_string(n);
    tmp.push_back('3');
    ll aux = stoi(tmp);
    return aux;
}

ll addZero(ll n){
    string tmp = to_string(n);
    tmp.push_back('0');
    ll aux = stoi(tmp);
    return aux;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> k){
        memset(rTres, 0, sizeof(rTres));
        memset(rZero, 0, sizeof(rZero));
        f.push({1, 0, 3 % k, 3});
        rTres[3 % k] = 1;

        while(rTres[0] == 0 || rZero[0] == 0){
            frResto = f.front().resto;
            frQntdTres = f.front().qntdTres;
            frQntdZero = f.front().qntdZero;
            frLastDigit = f.front().ultimoDigit;
            if(frResto == 0) break;
            if(frLastDigit == 3){
                ll putThree = addThree(frResto);
                ll aumentaTres = frQntdTres + 1;
                if(rTres[putThree % k] == 0){
                    f.push( {aumentaTres, frQntdZero, putThree % k, 3} );
                    rTres[putThree % k] = 1;
                }
            }
            ll putZero = addZero(frResto);
            ll aumentaZeros = frQntdZero + 1;

            if(rZero[putZero % k] == 0){
                f.push( {frQntdTres, aumentaZeros, putZero % k, 0} );
                rZero[putZero % k] = 1;
            }
            f.pop();
        }
        cout << frQntdTres + frQntdZero << " " << frQntdTres << " " << frQntdZero << endl;

        while (!f.empty()){
            f.pop();
        }
    }
    
    return 0;
}