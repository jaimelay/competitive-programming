#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = s.size();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    vector<int> z;
    while(cin >> str){
        if(str == "*") break;
        z = z_function(str);
        int tamT = 0;
        int tam = z.size();
        for(int i = 0; i < tam; i++){
            if(z[i] == tam - i && tam % z[i] == 0){
                tamT = z[i];
            }
        }
        string t = str.substr(0, tamT);
        if(tamT == 0){
            cout << 1 << endl;
            continue;
        }
        bool isEqual = true;
        int j = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != t[j++]) isEqual = false;
            if(j == tamT) j = 0;
        }
        if(isEqual) cout << str.size()/tamT << endl;
        else cout << 1 << endl;
    }
    return 0;
}