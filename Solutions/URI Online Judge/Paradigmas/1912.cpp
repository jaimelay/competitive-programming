#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-10;

int compara(long double a, long double b){
    if(b + EPS < a) return 1;
    if(a + EPS < b) return -1;
    return 0;
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double maiorAltura;
    
    long long n, a;
    long double h;

    while(cin >> n >> a){
        long long alturas[n];
        if(n == 0 && a == 0) break;
        for(int i = 0; i < n; i++){
            cin >> alturas[i];
        }

        long long areaTotal = accumulate(alturas, alturas + n, 0LL);

        if(areaTotal == a){
            cout << ":D" << endl;
            continue;
        } 
        if(a > areaTotal){
            cout << "-.-" << endl;
            continue;
        }

        sort(alturas, alturas + n);

        long double l = 0.0, r = alturas[n - 1], m = 0.0, areaAtual = 0.0;

        while(compara(l, r) == -1){
            areaAtual = 0.0;
            m = (l + r) * 0.5;
            for(int i = n - 1; i >= 0; i--){
                if(alturas[i] > m) areaAtual += alturas[i] - m;
                else break;
            }
            if(compara(areaAtual, a) == 0){
                l = m;
                break;
            }
            if(compara(a, areaAtual) == 1) r = m;
            else l = m;
        }
        cout << fixed << setprecision(4) << l << endl;
    }
    return 0;
}