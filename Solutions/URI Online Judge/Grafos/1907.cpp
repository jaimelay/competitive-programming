#include <bits/stdc++.h>

using namespace std;

char figura[1050][1050];
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1};

bool isInFigura(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    return figura[i][j] == '.';
}

void dfs(int i, int j){
    figura[i][j] = 'o';
    for(int k = 0; k < 4; k++)
        if(isInFigura(i + dx[k], j + dy[k]))
            dfs(i + dx[k], j + dy[k]);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", figura[i]);

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(figura[i][j] == '.'){
                ans++;
                dfs(i, j);
            }

    printf("%d\n", ans);
    return 0;
}