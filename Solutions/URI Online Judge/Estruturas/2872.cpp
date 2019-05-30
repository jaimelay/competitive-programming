#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string package, s, p;
    vector<pair<string, string>> pacotes;

    while(cin >> n){
        while(cin >> s){
            if(s != "Package") break;
            cin >> p;
            pacotes.push_back({s, p});
        }

        sort(pacotes.begin(), pacotes.end());

        for(int i = 0; i < pacotes.size(); i++)
            cout << pacotes[i].first << " " << pacotes[i].second << endl;
        cout << endl;

        pacotes.clear();
    }
    
    return 0;
}