#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    string w;
    cin >> t;
    while(t--){
        cin >> w;
        if(w == "1" || w == "4" || w == "78")
            cout << "+" << endl;
        else if(w[w.size() - 1] == '5' && w[w.size() - 2] == '3')
            cout << "-" << endl;
        else if(w[0] == '9' && w[w.size() - 1] == '4')
            cout << "*" << endl;
        else
            cout << "?" << endl;
    }
    return 0;
}