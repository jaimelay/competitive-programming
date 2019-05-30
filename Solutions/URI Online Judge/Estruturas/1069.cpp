#include <bits/stdc++.h>

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    stack<char> p;
    cin >> n;
    while(n--){
        cin >> s;
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        // cout << s << endl;
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<') l++;
            else if(s[i] == '>'){
                if(l > 0){
                    r++;
                    l--;
                }
            }
        }
        cout << r << endl;
    }
    return 0;
}