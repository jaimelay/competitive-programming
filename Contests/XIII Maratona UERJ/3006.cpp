#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define debugArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        string s;

        cin >> s;

        int n = (int)s.size();
        
        vector<tuple<int, int, int>> r_left;
        int last_c = -1, last_f = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                r_left.push_back({ i, last_c, last_f });
            } else if (s[i] == 'C') {
                last_c = i;
            } else if (s[i] == 'F') {
                last_f = i;
            }
        }

        vector<tuple<int, int, int>> r_right;
        last_c = -1, last_f = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'R') {
                r_right.push_back({ i, last_c, last_f });
            } else if (s[i] == 'C') {
                last_c = i;
            } else if (s[i] == 'F') {
                last_f = i;
            }
        }

        reverse(r_right.begin(), r_right.end());

        int ans = INF;
        for (int i = 0; i < (int)r_left.size(); i++) {
            int pos_r, left_c, left_f, right_c, right_f;
            tie(pos_r, left_c, left_f) = r_left[i];
            tie(pos_r, right_c, right_f) = r_right[i];

            ans = min({
                ans,
                (left_c != -1 && left_f != -1 ? (pos_r - min(left_c, left_f)):(INF)),
                (right_c != -1 && right_f != -1 ? (max(right_c, right_f) - pos_r):(INF)),
                (left_c != -1 && right_f != -1 ? (2 * (pos_r - left_c) + (right_f - pos_r)):(INF)),
                (left_f != -1 && right_c != -1 ? (2 * (pos_r - left_f) + (right_c - pos_r)):(INF)),
                (left_f != -1 && right_c != -1 ? (2 * (right_c - pos_r) + (pos_r - left_f)):(INF)),
                (left_c != -1 && right_f != -1 ? (2 * (right_f - pos_r) + (pos_r - left_c)):(INF)),
            });
        }

        cout << ans << endl;
    }

    return 0;
}