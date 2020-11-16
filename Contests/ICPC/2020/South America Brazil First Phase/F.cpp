#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int PL = 0, PR = 0;
    int GL = 0, GR = 0;
    bool side = false;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'Q' && i == (int)s.size() - 1) {
            cout << GL << (GL > GR ? " (winner)":"") << " - " << GR << (GR > GL ? " (winner)":"") << endl;
            continue;
        }

        if (s[i] == 'Q') {
            cout << GL << " (" << PL << (side == false ? "*)":")") << " - " << GR << " (" << PR << (side == true ? "*)":")") << endl;
            continue;
        }

        if (side == false) { 
            if (s[i] == 'R') {
                side = true;
                PR++;
            } else if (s[i] == 'S') {
                PL++;
            }
        } else {
            if (s[i] == 'R') {
                side = false;
                PL++;
            } else if (s[i] == 'S') {
                PR++;
            }
        }

        if (PL == 10 || (PL >= 5 && PL - PR >= 2)) {
            GL++;
            PL = 0;
            PR = 0;
        } else if (PR == 10 || (PR >= 5 && PR - PL >= 2)) {
            GR++;
            PL = 0;
            PR = 0;
        }
    }

    return 0;
}