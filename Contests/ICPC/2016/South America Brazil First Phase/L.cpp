#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int mat[220][220], vis[220][220];
int n, m;

int BFS(pair<int, int> s) {
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = 1;

    int color = mat[s.first][s.second];
    int area_size = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int new_row = x + dx[k];
            int new_col = y + dy[k];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && mat[new_row][new_col] == color && !vis[new_row][new_col]) {
                q.push({ new_row, new_col });
                vis[new_row][new_col] = 1;
                area_size++;
            }
        }
    }

    return area_size;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                ans = min(ans, BFS({ i, j }));
            }
        }
    }

    cout << ans << endl;

    return 0;
}