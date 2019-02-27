#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
    int xi, yi, xf, yf, v;
    while(cin >> xi >> yi >> xf >> yf >> v){
        int xInfEsq, yInfEsq, xSupDir, ySupDir;
        cin >> xInfEsq >> yInfEsq >> xSupDir >> ySupDir;

        double distCasaSup = sqrt(pow(xi - xInfEsq, 2) + pow(yi - ySupDir, 2));
        double distCasaInf = sqrt(pow(xi - xInfEsq, 2) + pow(yi - yInfEsq, 2));
        double distTerreno = xSupDir - xInfEsq;
        double distTerrEscoSup = sqrt(pow(xf - xSupDir, 2) + pow(ySupDir - yf, 2));
        double distTerrEscoInf = sqrt(pow(xSupDir - xf, 2) + pow(yInfEsq - yf, 2));
        
        double totalCima = distCasaSup + distTerrEscoSup;
        double totalBaixo = distCasaInf + distTerrEscoInf;
        
        double distMenor;
        if(totalCima > totalBaixo){
            distMenor = totalBaixo + distTerreno;
        }else{
            distMenor = totalCima + distTerreno;
        }
        cout << fixed << setprecision(1);
        double tempo = distMenor/v;
        cout << tempo << endl;
    }
    return 0;
}