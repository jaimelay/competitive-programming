#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string mensagem;
    int n;
    int cont = 0;
    map<string, int> tabela;

    while(cin >> n >> mensagem){
        for(int i = 0; i < mensagem.size(); i++){
            string tmp = mensagem.substr(i, n);
            if(!tabela[tmp] == 1) tabela[tmp] = 1;
            else tabela[tmp]++;
        }

        int maior = 0;
        string maiorStr;
        for (std::map<string,int>::iterator it=tabela.begin(); it!=tabela.end(); ++it){
            if(it->second > maior){
                maiorStr = it->first;
                maior = it->second;
                //std::cout << it->first << " => " << it->second << '\n';
            }
        }
        cout << maiorStr << endl;
        tabela.clear();
    }
    return 0;
}