#include <bits/stdc++.h>

using namespace std;

vector<char> eq;
map<int, string> mp;

void init(){
    int aux = '1';
    for(int i = 0; i < 17; i++) {
        if(i & 1){
            eq.push_back('*');
        } else {
            eq.push_back(aux);
            aux++;
        }
    }
}

int eq_result(){
    int value = 0, tmp = 0, cnt = 0;
    char op;
    for(auto i : eq){
        if(i != '*'){
            if(i >= '1' && i <= '9'){
                tmp = (tmp * 10) + (i - '1' + 1);
            }else if(i == '+'){
                if(cnt == 0){
                    value = tmp;
                }else{
                    if(op == '+') value += tmp;
                    else value -= tmp;
                }
                op = '+';
                tmp = 0;
                cnt++;
            }else if(i == '-'){
                if(cnt == 0){
                    value = tmp;
                }else{
                    if(op == '+') value += tmp;
                    else value -= tmp;
                }
                op = '-';
                tmp = 0;
                cnt++;
            }
        }
    }

    if(op == '+') value += tmp;
    else value -= tmp;
    
    return value;
}

void solve() {
    string s;
    for(auto i : eq)
        if(i != '*') s.push_back(i);

    int result = eq_result();
    mp[result] = s;
}

void gen(){
    for(int i = 1; i < 17; i += 2) {
        for(int control = 0; control <= 1; control++){
            eq[i] = control & 1 == true ? '+' : '-';
            for(int j = i+2; j < 17; j += 2) {
                eq[j] = '+';
                for(int k = j+2; k < 17; k +=2) {
                    eq[k] = '+';
                    solve();
                    eq[k] = '-';
                    solve();
                    eq[k] = '*';
                }
                eq[j] = '-';
                for(int k = j+2; k < 17; k +=2) {
                    eq[k] = '+';
                    solve();
                    eq[k] = '-';
                    solve();
                    eq[k] = '*';
                }
                eq[j] = '*';
            } 
        }
        eq[i] = '*';
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    gen();

    int n, d;

    cin >> n;
    while(n--){
        cin >> d;
        cout << mp[d] << " = " << d << '\n';
    }
    return 0;
}