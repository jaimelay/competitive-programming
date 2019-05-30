#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    int x;
    for(int i = 0; i < n.size(); i++){
    	x += n[i] - '0';
	}
    cout << x%3 << endl;
    
    return 0;
}