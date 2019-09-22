// Acha o menor valor em um array de tamanho n.
int menor = *min_element(a,a+n); 
// Conta quantos numeros 3 aparecem no vector v.
int qntd = count(v.begin(),v.end(),3); 
// Calcula o MDC entre dois numeros. OBS: Tomar cuidado com long long.
int mdc = __gcd(a,b); 
// Calcula o numero de 1's na representacao binaria do x.
// OBS: Usar __builtin_popcountll quando x for long long;
int qntdDeUm = __builtin_popcount(x); 
// Soma todos os valores do vetor com o valorInicial
int soma = accumulate(vetor.begin(), vetor.end(), valorInicial); 
// Preenche o vetor acumulando o valorInicial
iota(vetor.begin(), vetor.end(), valorInicial);
// Preenche o vetor com o valor
fill(vetor.begin(), vetor.end(), valor);                  