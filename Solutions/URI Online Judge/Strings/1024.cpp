#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string msg;
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, msg);

        for(int i = 0; i < msg.size(); i++)
            if(isalpha(msg[i]))
                msg[i] += 3;
    
        reverse(msg.begin(), msg.end());

        int mid = msg.size()/2;
        for(int i = mid; i < msg.size(); i++)
            msg[i]--;
        cout << msg << endl;
    }
    return 0;
}