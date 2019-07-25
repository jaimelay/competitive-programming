#include <bits/stdc++.h>

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string w;
    int n;
    cin >> n;
    while(n--){
        cin >> w;
        if(w.size() == 5) cout << "3" << endl;
        else{
            int cont = 0;
            string um = "one";
            for(int i = 0; i < w.size(); i++){
                if(w[i] != um[i]) cont++;
            }
            if(cont > 1) cout << "2" << endl;
            else cout << "1" << endl;
        }
    }

    return 0;
}