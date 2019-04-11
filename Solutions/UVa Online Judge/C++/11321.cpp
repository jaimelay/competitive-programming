#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int n, m, x;

bool compare(int a, int b){
    int m1 = a % m;
    int m2 = b % m;
    if(m1 == m2){
        if(a % 2 == 0 && b % 2 == 0){
            return a < b;
        }else if(a % 2 != 0 && b % 2 != 0){
            return a > b;
        }else{
            return a % 2 != 0;
        }
    }else{
        return m1 < m2;
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            cout << n << " " << m << endl;
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), compare);
        cout << n << " " << m << endl;
        for(int i = 0; i < n; i++)
            cout << v[i] << endl;
        v.clear();
    }
    return 0;
}