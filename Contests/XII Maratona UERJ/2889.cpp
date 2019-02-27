#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Times {
    int id;
    int gols;
    int pontuacao;
};

struct Primeiro {
    struct Times t;
};

struct Vice {
    struct Times t;
};

int p[1000001], v[1000001];

int main(void){
    int n, m, t1, p1, t2, p2;

    vector<Times> time;
    vector<Primeiro> primeiro;
    vector<Vice> vice;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
    Primeiro aux = { 0, 0, 0 };
    primeiro.push_back(aux);
    Vice aux2 = { 0, 0, 0 };
    vice.push_back(aux2);
    cin >> n;

    for(int i = 1; i <= n; i++){
        Times temp = { i, 0, 0 };
        time.push_back(temp);
    } 

    while(cin >> m){
        if(m == 0) break;
        for(int i = 0; i < m; i++){
            cin >> t1 >> p1 >> t2 >> p2;
            if(p1 == p2){
                time[t1 - 1].gols += p1;
                time[t2 - 1].gols += p2;
                time[t1 - 1].pontuacao += 1;
                time[t2 - 1].pontuacao += 1;
            }else if(p1 > p2){
                time[t1 - 1].gols += p1;
                time[t2 - 1].gols += p2;
                time[t1 - 1].pontuacao += 3;
            }else if(p2 > p1){
                time[t1 - 1].gols += p1;
                time[t2 - 1].gols += p2;
                time[t2 - 1].pontuacao += 3;
            }
        }

        //cout << "TIMES: " << endl;
        //for(int i = 0; i < n; i++)
        //    cout << "Nome: " << time[i].id << " - Gols: " << time[i].gols << " - Pontuacao: " << time[i].pontuacao << endl;
        //cout << endl;

        for(int i = 0; i < time.size(); i++){
            if(time[i].pontuacao > primeiro[0].t.pontuacao){
                vice[0].t.id = primeiro[0].t.id;
                vice[0].t.pontuacao = primeiro[0].t.pontuacao;
                vice[0].t.gols = primeiro[0].t.gols;

                primeiro[0].t.id = time[i].id;
                primeiro[0].t.pontuacao = time[i].pontuacao;
                primeiro[0].t.gols = time[i].gols;
            }else if(time[i].pontuacao == primeiro[0].t.pontuacao){
                if(time[i].gols > primeiro[0].t.gols){
                    vice[0].t.id = primeiro[0].t.id;
                    vice[0].t.gols = primeiro[0].t.gols;

                    primeiro[0].t.id = time[i].id;
                    primeiro[0].t.gols = time[i].gols;
                }else if(time[i].gols == primeiro[0].t.gols){
                    if(time[i].id < primeiro[0].t.id){
                        vice[0].t.id = primeiro[0].t.id;
                        primeiro[0].t.id = time[i].id;
                    }else{
                        vice[0].t.id = time[i].id;
                        vice[0].t.gols = time[i].gols;
                        vice[0].t.pontuacao = time[i].pontuacao;
                    }
                }else{
                    vice[0].t.id = time[i].id;
                    vice[0].t.gols = time[i].gols;
                    vice[0].t.pontuacao = time[i].pontuacao;
                }
            }else{
                if(time[i].pontuacao > vice[0].t.pontuacao){
                    vice[0].t.id = time[i].id;
                    vice[0].t.pontuacao = time[i].pontuacao;
                    vice[0].t.gols = time[i].gols;
                }else if(time[i].pontuacao == vice[0].t.pontuacao){
                    if(time[i].gols > vice[0].t.gols){
                        vice[0].t.id = time[i].id;
                        vice[0].t.gols = time[i].gols;
                    }else if(time[i].gols == vice[0].t.gols){
                        if(time[i].id < vice[0].t.id){
                            vice[0].t.id = time[i].id;
                        }
                    }else{
                        vice[0].t.id = time[i].id;
                        vice[0].t.gols = time[i].gols;
                        vice[0].t.pontuacao = time[i].pontuacao;
                    }
                }
            }
        }
        //cout << "PRIMEIRO: " << endl;
        //cout << "Nome: " << primeiro[0].t.id << " - Gols: " << primeiro[0].t.gols << " - Pontuacao: " << primeiro[0].t.pontuacao << endl;
        //cout << endl;

        //cout << "VICE: " << endl;
        //cout << "Nome: " << vice[0].t.id << " - Gols: " << vice[0].t.gols << " - Pontuacao: " << vice[0].t.pontuacao << endl;
        //cout << endl;

        p[primeiro[0].t.id - 1] += 1;
        v[vice[0].t.id - 1] += 1;

        //for(int i = 0; i < p.size(); i++){
        //    cout << p[i] << " ";
        //    cout << v[i] << endl;
        //}
        // LIMPA OS VECTORS
        time.clear();
        for(int i = 1; i <= n; i++){
            Times temp = { i, 0, 0 };
            time.push_back(temp);
        }

        primeiro.clear();
        Primeiro aux = { 0, 0, 0 };
        primeiro.push_back(aux);
        vice.clear();
        Vice aux2 = { 0, 0, 0 };
        vice.push_back(aux2);
    }
    int qntdPrimeiro = 0, qntdVice = 0, primeiroColocado, segundoColocado;

    for(int i = 0; i < n; i++){
        if(p[i] > qntdPrimeiro){
            qntdPrimeiro = p[i];
            primeiroColocado = i + 1;
        }
        if(v[i] > qntdVice){
            qntdVice = v[i];
            segundoColocado = i + 1;
        }
    }

    if(segundoColocado == 1){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}