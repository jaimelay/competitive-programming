#include <bits/stdc++.h>

using namespace std;

#define MAX 30000020LL

long long int n;
bool sieve[MAX+1];
vector<long long int> primes;

void SieveOfEratosthenes() 
{ 
    memset(sieve, true, sizeof(sieve)); 
  
    sieve[1] = false; 
  
    for (int p = 2; p * p <= MAX; p++) { 
  
        // If prime[p] is not changed, then it is a prime 
        if (sieve[p] == true) { 
  
            // Set all multiples of p to non-prime 
            for (int i = p * 2; i <= MAX; i += p) 
                sieve[i] = false; 
        } 
    } 
}

void pegaPrimos(){
    for(int i=2; i<MAX; i++){
        if(sieve[i]==true) primes.push_back(i);
    }
}

int factor(long long  int x){
    int i=0, cont, resp=1, contImpar=0;
    long long int aux=x;

    if(x==0 || x==1 || x==2) return 1;

    while(aux%2==0){
        aux=aux/2;
    }

    for(int i=1; i<primes.size(); i++){
        cont=0;
        //cout<<aux<<endl;
        if(aux==0 || aux==1) return resp;
        if(aux%primes[i]==0) contImpar++;
        while(aux%primes[i]==0){
            aux=aux/primes[i];
            cont++;
        }
        resp*=(cont+1);
    }
    if(resp==1) return 2;
    if(aux==1) return resp;
    else return resp*2;
}


int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    SieveOfEratosthenes();
    pegaPrimos();

    while(cin>>n){
        cout<<factor(n)<<endl;
    }

}