#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX 100000
#define MOD 1000007

typedef long long int lli;

int n, d;
string num, ans;

void solve(){
    int last=-1, maior=0, tam=n-d;

    for(int i=tam; i>0; i--){
        maior=0;
        //cout<<"Indo do "<<last<<" até o "<<num.size()-i<<endl;
        
        for(int j=last+1; j<=num.size()-i; j++){ 
            if(num[j]>maior){
                last=j;
                maior=num[j];
            }
            if(maior==9) break;
        }
        ans.push_back(maior);
    }

}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>n>>d){
        if(n==0 and d==0) break;
        ans.clear();

        cin>>num;
        solve();
        cout<<ans<<endl;

    }

    return 0;
}