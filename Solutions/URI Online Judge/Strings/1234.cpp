#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string palavras;
    while(getline(cin, palavras)){
        bool upper = true;
        for(int i = 0; i <= palavras.size(); i++){
            if(palavras[i] == ' ')
                continue;
            if(isalpha(palavras[i])){
                if(upper)
                    palavras[i] = toupper(palavras[i]);
                else
                    palavras[i] = tolower(palavras[i]);
                upper = !upper;
            }
        }
        cout << palavras << endl;
    }
    return 0;
}