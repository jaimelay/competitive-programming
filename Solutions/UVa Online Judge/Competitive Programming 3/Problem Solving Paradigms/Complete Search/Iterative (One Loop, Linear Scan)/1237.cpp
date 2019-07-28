#include <bits/stdc++.h>

using namespace std;

struct Maker{
    string name;
    int lowest;
    int highest;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, d, q, p;

    cin >> t;
    while(t--){
        cin >> d;
        vector<Maker> makers(d);
        for(int i = 0; i < d; i++){
            cin >> makers[i].name >> makers[i].lowest >> makers[i].highest;
        }
        cin >> q;
        while(q--){
            cin >> p;
            string ans;
            int flag = 0;
            for(int i = 0; i < makers.size(); i++){
                if(p >= makers[i].lowest && p <= makers[i].highest){
                    ans = makers[i].name;
                    flag++;
                }
            }
            if(flag == 1) cout << ans << endl;
            else cout << "UNDETERMINED" << endl;
        }
        makers.clear();
        if(t > 0)
            cout << endl;
    }

    return 0;
}