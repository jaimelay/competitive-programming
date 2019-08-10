#include <bits/stdc++.h>

using namespace std;

int v[20], soma = 0, t, n;
map<vector<int>, bool> m;
vector<int> ans;

void solve(int soma, int pos, int k){
    if(soma == t){
        if(m[ans] == true) return;
        m[ans] = true;
        for(int i = 0; i < k; i++){
            cout << ans[i];
            if(i < k - 1) cout << "+";
        }
        cout << endl;
        return;
    }
    if(soma > t || pos >= n) return;
    for(int i = pos; i < n; i++){
        ans.push_back(v[i]);
        solve(soma + v[i], i + 1, k + 1);
        ans.pop_back();
    }   
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> t >> n, t, n){
        memset(v, 0, sizeof(v));
        ans.clear();
        m.clear();

        for(int i = 0; i < n; i++) cin >> v[i];
        cout << "Sums of " << t << ":" << endl;
        solve(0, 0, 0);
        if(m.empty()) cout << "NONE" << endl;
    }
    return 0;
}