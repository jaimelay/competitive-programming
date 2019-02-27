#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdio>

using namespace std;

int main(void){
    int transf, p;
    string package;
    vector<int> v;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(!cin.eof()){
        cin >> transf;
        while(getline(cin, package)){
            if(package != "0"){
                cin >> p;
                v.push_back(p);
            }else{
                break;
            }
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(v[i] % 10 == v[i]) cout << "Package 00" << v[i] << endl;
            else if(v[i] % 100 == v[i]) cout << "Package 0" << v[i] << endl;
            else cout << "Package " << v[i] << endl;
        }
        cout << endl;
        v.clear();
    }
    return 0;
}