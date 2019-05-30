#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

typedef struct {int x, y;}Ponto;
typedef struct {Ponto p, q;}Segmento;
Ponto pol[100000], ch[100000]; //vetores globais

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long long a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
}

double AreaPoligono(Ponto *pol, int n)
{  long long c;  int i;
   pol[n] = pol[0];
   c = 0;  for (i=0; i<n; i++) c= c + pol[i].x*pol[i+1].y-pol[i+1].x*pol[i].y;
   return c/2.0;
}

void Quicksort(Ponto *pol, int e, int d)
// O ponto 0 fica fixo na ordena��o, pois tem o menor x
{  int i,j,k;  Ponto t,r;  long long d0, d1, d2;
   if (d > e)
   {  i=e;  j=d;  t=pol[(e+d)/2];
      d1= pol[0].x-t.x;  d2= pol[0].y-t.y;  d0=d1*d1+d2*d2;
      while(i<=j)
      {  while(1)
         {  k=SentidoPercurso(pol[0],pol[i],t);
            if (k==1) i++;
            else if (k==0)
            {  d1= pol[0].x-pol[i].x;  d2= pol[0].y-pol[i].y;  d1= d1*d1+d2*d2;
               if (d1 < d0) i++;
               else break;
            }   
            else break;
         }
         while(1)
         {  k=SentidoPercurso(pol[0],t,pol[j]);
            if (k==1) j--;
            else if (k==0)
            {  d1= pol[0].x-pol[j].x;  d2= pol[0].y-pol[j].y;  d1= d1*d1+d2*d2;
               if (d0 < d1) j--;
               else break;
            }
            else break;
         }  
         if (i<=j) {r=pol[i];  pol[i]=pol[j];  pol[j]=r;  i++; j--;}
      }
      Quicksort(pol, e,j);  Quicksort(pol, i,d);
   }
}     

void OrdenaPontosy(Ponto *pol, int tp)
/*   Ordena pontos por �ngulo, escolhendo como refer�ncia o ponto mais embaixo e mais
   � esquerda. */
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++) 
      if ((pol[i].y < pol[m].y)||(pol[i].y==pol[m].y)&&(pol[i].x<pol[m].x)) m=i;
   p=pol[0];  pol[0]=pol[m];  pol[m]=p;
   Quicksort(pol, 1,tp-1);
}

int ConvexHull(Ponto *pol, int tp, Ponto *ch, int &tc)
{   int i,j,topo;
    OrdenaPontosy(pol, tp);
    /*Repete o ponto inicial no final*/
    ch[0]= pol[0]; pol[tp]= pol[0];
    j= 1;
    /* Elimina pontos iniciais colineares */
    while (SentidoPercurso(ch[0],pol[j],pol[j+1])==0) j++;
    ch[1]= pol[j];  ch[2]= pol[j+1];
    topo= 2;
    for (i= j+2; i<= tp; i++)
    {   while (SentidoPercurso(ch[topo-1], ch[topo], pol[i]) <= 0) topo--;
        topo++;  ch[topo]= pol[i];
    }
    tc = topo;
    return (topo);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, nv;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5){
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0 && x4 == 0 && y4 == 0 && x5 == 0 && y5 == 0) break;
        pol[0].x = x1; pol[0].y = y1;
        pol[1].x = x2; pol[1].y = y2;
        pol[2].x = x3; pol[2].y = y3;
        pol[3].x = x4; pol[3].y = y4;
        pol[4].x = x5; pol[4].y = y5;
        nv = ConvexHull(pol, 5, ch, nv);
        cout<<"Contorno Convexo com " << nv-1 << " pontos:" << endl;
        for (int i=0; i<=nv; i++) cout<< ch[i].x <<" " <<ch[i].y <<" " << endl;
        cout << AreaPoligono(ch, 5) << endl;
    }

    return 0;
}