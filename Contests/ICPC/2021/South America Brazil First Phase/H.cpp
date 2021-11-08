#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

const int MAXN = 100010;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> colors;
    priority_queue<int, vector<int>, greater<int>> numbers[MAXN];

    for (int i = 0, number, color; i < n; i++) {
        cin >> number >> color;
        colors.push_back(color);
        numbers[color].push(number);
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i] = numbers[colors[i]].top();
        numbers[colors[i]].pop();
    }

    cout << (is_sorted(ans.begin(), ans.end()) ? "Y" : "N") << endl; 

    return 0;
}