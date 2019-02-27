// https://www.urionlinejudge.com.br/judge/pt/problems/view/1865

#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);

    int t, x;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> x;
        if(s == "Thor") cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}