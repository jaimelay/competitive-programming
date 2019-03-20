#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> k >> n;
        vector<long long> fibo;
        for(int i = 0; i < k; i++)
            fibo.push_back(i);

        if(k > n){
            cout << fibo[n - 1] << endl;
        }else{
            long long soma = 0;
            long long tmp = n - k;
            while(tmp--){
                soma = accumulate(fibo.end() - k, fibo.end(), 0LL);
                fibo.push_back(soma % 1000007);
            }
            cout << fibo[n - 1] % 1000007 << endl;
        }
    }
    return 0;
}