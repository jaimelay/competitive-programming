#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int T[1000001], R[1000001];

int main(void){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    int tot = 0;
    int d;
    memset(T, 0, sizeof(T));
    for(int k = 1; k <= n - 1; k++){
        d = __gcd(k, n);
        if(d == k){
            memset(R, 0, sizeof(R));
            for(int j = 0; j < n; j++)
                if(s[j] == 'P')
                    R[j % k] = 1;

            for(int r = 0; r <= k - 1; r++)
                if(R[r] == 0)
                    T[k] = 1;
        }
        tot += T[d];
    }
    cout << tot << endl;
    return 0;
}