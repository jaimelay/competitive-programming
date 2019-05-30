#include <bits/stdc++.h>

using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, d, tam;
    string num;
    deque<char> deq;
    while(cin >> n >> d){
        if(n == 0 && d == 0) break;
        cin >> num;
        tam = n - d;
        for(int i = 0; i < n; i++){
            if(deq.empty() || num[i] < deq.back())
                deq.push_back(num[i]);
            else{
                while(!deq.empty() && deq.back() < num[i] && d > 0){
                    deq.pop_back();
                    d--;
                }
                deq.push_back(num[i]);
            }
        }

        for (int i = 0; i < tam; i++){
            cout << deq.front();
            deq.pop_front();
        }
        cout << endl;
        deq.clear();
    }
    return 0;
}