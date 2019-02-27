#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

struct Aleta {
    int xi = 0;
    int yi = 0;
    int xf = 0;
    int yf = 0;
    double distPonto = 0;
    double distPontoReta = 0;
};

double distPontos(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double distPontoReta(double px, double py, double x1, double y1, double x2, double y2) {
    return fabs((y1 - y2) * px + (x2 - x1) * py + x1 * y2 - x2 * y1)/sqrt((y1 - y2) * (y1 - y2) + (x2 - x1) * (x2 - x1));
}

int main(void){
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, l, h, yi, xf, yf;
    while(cin >> n){
        cin >> l >> h;
        Aleta a[10000];
        for(int i = 1; i <= n; i++){
            cin >> yi >> xf >> yf;
            if(i % 2 != 0) a[i] = { 0, yi, xf, yf, 0, 0 };
            else a[i] = { l, yi, xf, yf, 0, 0 };
        }

        // PREENCHE DISTANCIA PONTO EXTREMO DE UMA ALETA ATÉ O INICIO DA OUTRA ALETA
        for(int i = 1; i < n; i++){
            a[i].distPonto = distPontos(xf, a[i + 1].xi, yf, a[i + 1].yi);
        }
        if(n % 2 != 0) a[n].distPonto = l - a[n].xf;
        else a[n].distPonto = a[n].xf;
        
        // PREENCHE DISTANCIA PONTO A RETA
        for(int i = 1; i < n; i++){
            a[i].distPontoReta = distPontoReta(xf, yf, a[i + 1].xi, a[i + 1].yi, a[i + 1].xf, a[i + 1].yf);
        }

        double menorDistPonto = 1.7976931348623158;
        for(int i = 1; i <= n; i++){
            cout << a[i].distPonto << " ";
            // if(a[i].distPonto < menorDistPonto)
            //     menorDistPonto = a[i].distPonto;
        }

        double menorDistPontoReta = 1.7976931348623158;
        for(int i = 1; i < n; i++){
            cout << a[i].distPontoReta << " ";
            // if(a[i].distPontoReta < menorDistPontoReta)
            //     menorDistPontoReta = a[i].distPontoReta;
        }

        cout << fixed << setprecision(2);
        cout << min(menorDistPonto, menorDistPontoReta) << endl;
    }

    return 0;
}