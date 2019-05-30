#include <bits/stdc++.h>

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    stack<char> p;
    while(cin >> s){
        // cout << s << endl;
        if(s.size() == 1){
            cout << "incorrect" << endl;
            continue;
        } 
        int cont = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                p.push(s[i]);
                cont++;
            }else if(s[i] == ')'){
                if(!p.empty()) p.pop();
                cont--;
            } 
        }
        if(p.empty() && cont == 0) cout << "correct" << endl;
        else cout << "incorrect" << endl;
        while(!p.empty()){
            p.pop();
        }
    }
    return 0;
}