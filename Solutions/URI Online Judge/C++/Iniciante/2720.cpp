#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool Compare(const pair<int,int> &a, const pair<int,int> &b){ 
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
} 

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, h, w, l, tam;
    long long id;
    vector<pair<long long, int>> maiores;
    set<int> maioresID;

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> id >> h >> w >> l;
            tam = h * w * l;
            maiores.push_back(make_pair(id, tam));
        }
        sort(maiores.begin(), maiores.end(), Compare);
        for(int i = 0; i < k; i++)
            maioresID.insert(maiores[i].first);
        int cont = 0;
        for(auto i : maioresID){
            cout << i;
            cont++;
            if(cont == k) cout << endl;
            else cout << " ";
        }
        maiores.clear();
        maioresID.clear();
    }
    return 0;
}