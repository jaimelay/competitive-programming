#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 510;

int query(int i, int j, int x, int y, vector<vector<int>> &mat) {
    return mat[x][y] - mat[x][j - 1] - mat[i - 1][y] + mat[i - 1][j - 1];
}

void printMat(vector<vector<int>> &mat, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mat[i][j] << " \n"[j == n];
        }
    }
    cout << endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    
    cin >> n >> p;

    vector<vector<int>> mat(n + 1, vector<int>(n + 1));

    int player1 = MAXN + 1;
    int player2 = MAXN + 2;

    for (int i = 0, x, y; i < p; i++) {
        cin >> x >> y;
        mat[x][y] = player1;
    }

    for (int i = 0, x, y; i < p; i++) {
        cin >> x >> y;
        mat[x][y] = player2;
    }

    printMat(mat, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] += mat[i - 1][j];
        }
    }

    printMat(mat, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] += mat[i][j - 1];
        }
    }

    printMat(mat, n);

    int ans1 = 0, ans2 = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int len = 0; max(i, j) + len <= n; len++) {
                int sum = query(i, j, i + len, j + len, mat);

                if (sum == 0) {
                    continue;
                }

                if (sum % player1 == 0) {
                    ans1++;
                } else if (sum % player2 == 0) {
                    ans2++;
                } else {
                    break;
                }
            }
        }
    }    

    cout << ans1 << " " << ans2 << endl;

    return 0;
}