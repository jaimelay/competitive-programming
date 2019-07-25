#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, string>> combVal;
    int b1, b2, b3, g1, g2, g3, c1, c2, c3;
    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){
        combVal.push_back({ b2 + b3 + c1 + c3 + g1 + g2, "BCG" }); // BCG
        combVal.push_back({ b2 + b3 + g1 + g3 + c2 + c1, "BGC" }); // BGC
        combVal.push_back({ c2 + c3 + b1 + b3 + g2 + g1, "CBG" }); // CBG
        combVal.push_back({ c2 + c3 + g1 + g3 + b1 + b2, "CGB" }); // CGB
        combVal.push_back({ g2 + g3 + b1 + b3 + c1 + c2, "GBC" }); // GBC
        combVal.push_back({ g2 + g3 + c1 + c3 + b1 + b2, "GCB" }); // GCB
        sort(combVal.begin(), combVal.end());
        cout << combVal[0].second << " " << combVal[0].first << endl;
        combVal.clear();
    }
    return 0;
}