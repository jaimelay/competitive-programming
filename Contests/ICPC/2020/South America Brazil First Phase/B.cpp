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

    int n;

    cin >> n;

    vector<vector<int>> mat(11, vector<int>(11));

    bool flag = false;

    for (int i = 0; i < n; i++) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if (d == 0) {
            for (int j = c; j <= c + l - 1; j++) {
                if (j > 10) {
                    flag = true;
                    break;
                }
                if (mat[r][j]) {
                    flag = true;
                }
                mat[r][j] = 1;
                
            }
        } else if (d != 0) {
            for (int j = r; j <= r + l - 1; j++) {
                if (j > 10) {
                    flag = true;
                    break;
                }
                if (mat[j][c]) {
                    flag = true;
                }
                mat[j][c] = 1;
            }
        }
    }

    if (!flag) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}